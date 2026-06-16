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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Step - 2: reverse the second half starting at Mid
        ListNode* rev = reverse(mid);
        ListNode* curr = head;

        // As the secondHalf is always smaller or equal than first Half
        while (rev != nullptr) {
            ListNode* temp1 = curr->next;
            ListNode* temp2 = rev->next;

            curr->next = rev;
            rev->next = temp1;

            curr = temp1;
            rev = temp2;
        }
    }
};
