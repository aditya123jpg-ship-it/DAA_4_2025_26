
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;


struct Node {
    string name;   
    float  price;  
    Node*  left;   
    Node*  right;  

    Node(string n, float p) {
        name  = n;
        price = p;
        left  = NULL;
        right = NULL;
    }
};



struct ArrayItem {
    string name;
    float  price;
};

const int MAX_ARRAY = 100;
ArrayItem itemArray[MAX_ARRAY];
int arraySize = 0;


class BST {
private:
    Node* root;

    Node* insertHelper(Node* node, string name, float price) {
        if (node == NULL)
            return new Node(name, price);

        if (name < node->name)
            node->left  = insertHelper(node->left,  name, price);
        else if (name > node->name)
            node->right = insertHelper(node->right, name, price);
        else
            cout << "  [!] Item already exists. Use Update to change price.\n";

        return node;
    }

    // Search recursively — also counts comparisons
    Node* searchHelper(Node* node, string name, int& comparisons) {
        if (node == NULL) {
            comparisons++;
            return NULL;
        }

        comparisons++;

        if (name == node->name)
            return node;
        else if (name < node->name)
            return searchHelper(node->left,  name, comparisons);
        else
            return searchHelper(node->right, name, comparisons);
    }

    // Find minimum node (used in delete)
    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // Delete recursively
    Node* deleteHelper(Node* node, string name, bool& found) {
        if (node == NULL) {
            found = false;
            return NULL;
        }

        if (name < node->name)
            node->left  = deleteHelper(node->left,  name, found);
        else if (name > node->name)
            node->right = deleteHelper(node->right, name, found);
        else {
            found = true;

            // Case 1: Leaf node
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            // Case 2: One child (right only)
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Case 3: One child (left only)
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 4: Two children — replace with inorder successor
            else {
                Node* successor   = findMin(node->right);
                node->name  = successor->name;
                node->price = successor->price;
                node->right = deleteHelper(node->right, successor->name, found);
            }
        }
        return node;
    }

    // Inorder traversal (gives sorted output)
    void inorderHelper(Node* node, int& count) {
        if (node == NULL) return;
        inorderHelper(node->left, count);
        count++;
        cout << "  " << count << ". " << node->name << "   \tRs. " << node->price << "\n";
        inorderHelper(node->right, count);
    }

    // Count total nodes
    int countHelper(Node* node) {
        if (node == NULL) return 0;
        return 1 + countHelper(node->left) + countHelper(node->right);
    }

    // Check if tree is empty (skewed check helper)
    bool isSkewed(Node* node) {
        if (node == NULL) return false;
        if (node->left != NULL && node->right != NULL) return false;
        if (node->left  != NULL) return isSkewed(node->left);
        if (node->right != NULL) return isSkewed(node->right);
        return true;
    }

public:
    BST() { root = NULL; }

    // ── PUBLIC METHODS ───────────────────────

    // 1. ADD ITEM
    void addItem(string name, float price) {
        root = insertHelper(root, name, price);
    }

    // 2. SEARCH ITEM
    void searchItem(string name) {
        int comparisons = 0;
        Node* result = searchHelper(root, name, comparisons);
        cout << "\n  [BST Search]\n";
        cout << "  Comparisons made : " << comparisons << "\n";
        if (result != NULL)
            cout << "  Item Found  : " << result->name << "  |  Price: Rs. " << result->price << "\n";
        else
            cout << "  Item NOT found in BST.\n";
    }

    // Internal search that returns comparisons (used for comparison feature)
    int searchComparisons(string name) {
        int comparisons = 0;
        searchHelper(root, name, comparisons);
        return comparisons;
    }

    // 3. DELETE ITEM
    void deleteItem(string name) {
        bool found = true;
        root = deleteHelper(root, name, found);
        if (found)
            cout << "  [✓] Item '" << name << "' deleted successfully.\n";
        else
            cout << "  [!] Item '" << name << "' not found.\n";
    }

    // 4. UPDATE PRICE
    void updatePrice(string name, float newPrice) {
        int comparisons = 0;
        Node* result = searchHelper(root, name, comparisons);
        if (result != NULL) {
            float old = result->price;
            result->price = newPrice;
            cout << "  [✓] Price updated: " << name << "  Rs." << old << " → Rs." << newPrice << "\n";
        } else {
            cout << "  [!] Item '" << name << "' not found.\n";
        }
    }

    // 5. DISPLAY INVENTORY (Inorder = sorted alphabetically)
    void display() {
        if (root == NULL) {
            cout << "  Inventory is empty.\n";
            return;
        }
        cout << "\n  ── Inventory (Sorted A→Z) ─────────────\n";
        cout << "  No.  Item Name         Price\n";
        cout << "  ────────────────────────────────────────\n";
        int count = 0;
        inorderHelper(root, count);
        cout << "  ────────────────────────────────────────\n";
        cout << "  Total items: " << count << "\n";
    }

    // 6. GET COUNT
    int count() {
        return countHelper(root);
    }

    // 7. SKEWED CHECK
    bool checkSkewed() {
        return isSkewed(root);
    }

    bool isEmpty() {
        return root == NULL;
    }
};

// ─────────────────────────────────────────────
//  ARRAY FUNCTIONS (for comparison)
// ─────────────────────────────────────────────

void arrayAddItem(string name, float price) {
    if (arraySize < MAX_ARRAY) {
        itemArray[arraySize].name  = name;
        itemArray[arraySize].price = price;
        arraySize++;
    }
}

// Linear search — returns comparison count
int arraySearch(string name) {
    int comparisons = 0;
    for (int i = 0; i < arraySize; i++) {
        comparisons++;
        if (itemArray[i].name == name)
            return comparisons;
    }
    return comparisons;
}

// ─────────────────────────────────────────────
//  HELPER: INPUT UTILITIES
// ─────────────────────────────────────────────

void printLine() {
    cout << "\n  ════════════════════════════════════════\n";
}

void printHeader() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║     INVENTORY MANAGEMENT SYSTEM      ║\n";
    cout << "  ║      BST + Algorithm Analysis        ║\n";
    cout << "  ╚══════════════════════════════════════╝\n";
}

void printMenu() {
    cout << "\n  ┌─────────────────────────────────────┐\n";
    cout << "  │              MAIN MENU              │\n";
    cout << "  ├─────────────────────────────────────┤\n";
    cout << "  │  1. Add Item                        │\n";
    cout << "  │  2. Search Item                     │\n";
    cout << "  │  3. Delete Item                     │\n";
    cout << "  │  4. Update Price                    │\n";
    cout << "  │  5. Display Inventory               │\n";
    cout << "  │  6. Compare: Array vs BST Search    │\n";
    cout << "  │  7. Complexity Analysis Demo        │\n";
    cout << "  │  8. Exit                            │\n";
    cout << "  └─────────────────────────────────────┘\n";
    cout << "  Enter choice: ";
}

// ─────────────────────────────────────────────
//  FEATURE 6: COMPARISON — Array vs BST
// ─────────────────────────────────────────────

void compareSearch(BST& bst) {
    if (bst.isEmpty()) {
        cout << "\n  [!] Inventory is empty. Add items first.\n";
        return;
    }

    string target;
    cout << "\n  Enter item name to search and compare: ";
    cin >> target;

    int bstComp   = bst.searchComparisons(target);
    int arrayComp = arraySearch(target);

    cout << "\n  ── Search Comparison ──────────────────────\n";
    cout << "  Searching for: " << target << "\n";
    cout << "  ─────────────────────────────────────────\n";
    cout << "  Method          Comparisons\n";
    cout << "  ─────────────────────────────────────────\n";
    cout << "  Array (Linear)  " << arrayComp << "\n";
    cout << "  BST             " << bstComp   << "\n";
    cout << "  ─────────────────────────────────────────\n";

    if (bstComp < arrayComp)
        cout << "  [Result] BST is FASTER by " << (arrayComp - bstComp) << " comparison(s)\n";
    else if (bstComp == arrayComp)
        cout << "  [Result] Both took equal comparisons.\n";
    else
        cout << "  [Note] BST took more comparisons (possibly skewed tree).\n";

    int n = bst.count();
    cout << "\n  [Complexity]\n";
    cout << "  Total items (n) = " << n << "\n";
    cout << "  BST Best Case   = O(log " << n << ") = ~" << (int)(log2(n)+1) << " comparisons\n";
    cout << "  Array Worst Case= O(n)  = " << n << " comparisons\n";
}

// ─────────────────────────────────────────────
//  FEATURE 7: COMPLEXITY ANALYSIS DEMO
// ─────────────────────────────────────────────

void complexityDemo(BST& bst) {
    cout << "\n  ── Complexity Analysis ────────────────────\n\n";

    cout << "  OPERATION    | BEST CASE  | WORST CASE\n";
    cout << "  ─────────────────────────────────────────\n";
    cout << "  Search       | O(log n)   | O(n)\n";
    cout << "  Insert       | O(log n)   | O(n)\n";
    cout << "  Delete       | O(log n)   | O(n)\n";
    cout << "  Display(all) | O(n)       | O(n)\n";
    cout << "  ─────────────────────────────────────────\n\n";

    cout << "  BEST CASE  (Balanced BST)\n";
    cout << "  → Items inserted in random order\n";
    cout << "  → Tree remains balanced\n";
    cout << "  → Max levels = log2(n)\n";
    cout << "  → Example: 7 items → only 3 levels\n\n";

    cout << "  WORST CASE (Skewed BST)\n";
    cout << "  → Items inserted in SORTED order\n";
    cout << "  → Tree becomes like a linked list\n";
    cout << "  → Apple → Banana → Mango → Orange\n";
    cout << "  → Search = O(n), same as array!\n\n";

    cout << "  INSIGHT:\n";
    cout << "  → BST is NOT always fast\n";
    cout << "  → Performance depends on tree structure\n\n";

    cout << "  ADVANCED FIX (Theory Only):\n";
    cout << "  → AVL Tree     : Auto-balances on every insert/delete\n";
    cout << "  → Red-Black Tree: Used in C++ map & Java TreeMap\n";
    cout << "  → Both guarantee O(log n) always\n";

    if (!bst.isEmpty()) {
        cout << "\n  [Current Tree Check]\n";
        int n = bst.count();
        cout << "  Items in tree: " << n << "\n";
        if (bst.checkSkewed())
            cout << "  Tree appears SKEWED → Worst case possible!\n";
        else
            cout << "  Tree appears BALANCED → Good performance!\n";
    }
    cout << "  ─────────────────────────────────────────\n";
}

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────

int main() {
    BST bst;
    int choice;
    string name;
    float price;

    printHeader();

    // Pre-load some sample data so the system isn't empty
    cout << "\n  [System] Loading sample inventory...\n";
    string sampleNames[] = {"Apple", "Milk", "Rice", "Bread", "Butter", "Eggs", "Sugar"};
    float  samplePrices[]= {30.0,    50.0,   70.0,   40.0,    90.0,    60.0,   45.0};
    for (int i = 0; i < 7; i++) {
        bst.addItem(sampleNames[i], samplePrices[i]);
        arrayAddItem(sampleNames[i], samplePrices[i]);
    }
    cout << "  [System] 7 sample items loaded.\n";

    do {
        printMenu();
        cin >> choice;

        switch (choice) {

            case 1: // ADD ITEM
                printLine();
                cout << "\n  ── Add New Item ────────────────────────\n";
                cout << "  Item name  : ";
                cin  >> name;
                cout << "  Item price : Rs. ";
                cin  >> price;
                if (price < 0) {
                    cout << "  [!] Price cannot be negative.\n";
                } else {
                    bst.addItem(name, price);
                    arrayAddItem(name, price);
                    cout << "  [✓] '" << name << "' added at Rs." << price << "\n";
                }
                break;

            case 2: // SEARCH ITEM
                printLine();
                cout << "\n  ── Search Item ─────────────────────────\n";
                cout << "  Item name: ";
                cin  >> name;
                bst.searchItem(name);
                break;

            case 3: // DELETE ITEM
                printLine();
                cout << "\n  ── Delete Item ─────────────────────────\n";
                cout << "  Item name: ";
                cin  >> name;
                bst.deleteItem(name);
                break;

            case 4: // UPDATE PRICE
                printLine();
                cout << "\n  ── Update Price ────────────────────────\n";
                cout << "  Item name  : ";
                cin  >> name;
                cout << "  New price  : Rs. ";
                cin  >> price;
                if (price < 0)
                    cout << "  [!] Price cannot be negative.\n";
                else
                    bst.updatePrice(name, price);
                break;

            case 5: // DISPLAY
                printLine();
                bst.display();
                break;

            case 6: // COMPARE
                printLine();
                compareSearch(bst);
                break;

            case 7: // COMPLEXITY DEMO
                printLine();
                complexityDemo(bst);
                break;

            case 8: // EXIT
                cout << "\n  Exiting system. Goodbye!\n\n";
                break;

            default:
                cout << "\n  [!] Invalid choice. Enter 1-8.\n";
        }

    } while (choice != 8);

    return 0;
}

/*
============================================================
  DRY RUN EXAMPLE (for report / viva)

  BST after inserting: Apple, Milk, Rice, Bread, Butter

              Apple
                \
               Milk
              /    \
           Bread   Rice
              \
             Butter

  Search "Rice":
  Step 1: Compare "Rice" vs "Apple" → go right  [comp=1]
  Step 2: Compare "Rice" vs "Milk"  → go right  [comp=2]
  Step 3: Compare "Rice" vs "Rice"  → FOUND     [comp=3]

  Array Search "Rice" → scans Apple, Milk, Rice  [comp=3]
  (With more items, BST wins bigger)

  Worst Case Demo:
  Insert Apple, Banana, Cherry (sorted order)
  Apple
    \
    Banana
       \
       Cherry  ← Skewed tree, search = O(n)
============================================================
*/
