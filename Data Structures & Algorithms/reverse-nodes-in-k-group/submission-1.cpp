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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = dummy;
        while (curr != nullptr)
        {
            ListNode* temp = curr;
            for (int i=0; i < k; i++)
            {
                if (temp == nullptr)
                    return dummy->next;
                temp = temp->next;
            }
            ListNode* next = temp;
            ListNode* newPrev = curr;
            for (int i=0; i < k; i++)
            {
                ListNode* l = curr->next;
                curr->next = next;
                next = curr;
                curr = l;
            }
            prev->next = next;
            prev = newPrev;
        }
        return dummy->next;
    }
};
