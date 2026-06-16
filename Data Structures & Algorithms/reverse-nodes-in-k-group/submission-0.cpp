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
    ListNode* help(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i=0;i<k;i++){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* group_prev = dummy;
        
        while(true){
            //Check whether there exist k groups
            ListNode* kth_node = group_prev;
            for(int i=0;i<k;i++){
                kth_node = kth_node->next;
                if(kth_node == nullptr){
                    return dummy->next;
                }
            }

            ListNode* group_next = kth_node->next;
            ListNode* group_start = group_prev->next;

            kth_node->next = nullptr;
            group_prev->next = help(group_start, k);

            group_start->next = group_next;

            group_prev = group_start;
        }
        return dummy->next;
    }
};
