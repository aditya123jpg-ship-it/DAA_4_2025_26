/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Name: Aditya Dubey
 //UID: 24BCS10457


class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *slower = head, *faster = head;

        while (faster!=nullptr && faster->next!=nullptr)
        {
            slower = slower->next;
            faster = faster->next->next;

            if (slower == faster)
            {
                slower = head;
                while (slower != faster)
                {
                    slower = slower->next;
                    faster = faster->next;
                }
                return slower;
            }
        }
        return NULL;
    }
};