/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        while(curr!=nullptr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        //Assigning the random pointer value
        curr = head;

        while(curr!=nullptr){
            if(curr->random!=nullptr){
                //curr ke next ka random is equal to curr ka random ka next;
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //Make it original
        Node* dummy = new Node(0);
        Node* tmp = dummy;
        curr = head;

        while(curr!=nullptr){
            Node* copy = curr->next;
            curr->next = copy->next;

            tmp->next = copy;
            tmp = tmp->next;

            curr = curr->next;
        }
        Node* result = dummy->next;
        delete dummy;
        return result;
    }
};
