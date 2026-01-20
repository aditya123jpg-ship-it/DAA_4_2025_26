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
//Name: Aditya Dubey
//UID: 24BCS10457


class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *last = NULL;
        ListNode *current = head;

        while (current!=NULL)
        {
            ListNode *temp = current->next;
            current->next = last;
            last = current;
            current = temp;
        }

        return last;
    }
};