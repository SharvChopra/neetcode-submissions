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
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }

        if (k == 1) {
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;

            while (lists[0] != nullptr) {
                curr->next = lists[0];
                lists[0] = lists[0]->next;
                curr = curr->next;
            }

            return dummy->next;
        }

        if (k >= 2) {
            ListNode* initialAns = mergeList(lists[0], lists[1]);

            ListNode* result;
            for (int i = 2; i < k; i++) {
                // Merge the 2 lists and store the value
                ListNode* ans = mergeList(initialAns, lists[i]);
                initialAns = ans;
            }

            return initialAns;
        }
        return nullptr;
    }
};
