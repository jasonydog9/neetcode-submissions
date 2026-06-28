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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        int min = 0;
        while (true)
        {
            int count = -1;
            for (ListNode*& l : lists)
            {
                count++;
                if (l == nullptr)
                    continue;
                if (lists[min] == nullptr || l->val < lists[min]->val)
                {
                    min = count;
                }
            }
            if (lists.size() == 0 || lists[min] == nullptr)
                break;
            
            ListNode*& temp = lists[min];
            ListNode* curr = temp;
            head->next = curr;
            temp = temp->next;
            curr->next = nullptr;
            head = head->next;
        }

        return dummy->next;
    }
};
