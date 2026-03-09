
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)
        { 
            return;
        }
        vector<ListNode*> con;
        ListNode* temp = head; 
        while(temp!=NULL)
        {
            con.push_back(temp);
            temp = temp->next;
        }
        int i = 0, j = con.size() - 1;
        while(i<j)
        {
            con[i++]->next = con[j];
            if(i==j) 
            {
                break;
            }
            con[j--]->next=con[i];
        }
        con[i]->next=NULL;
    }
    

};