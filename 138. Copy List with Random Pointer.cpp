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
      Node* iter = head;
        Node* front = head;
//         first step
        while(iter!= NULL){
            front = iter->next;
            Node* dummy = new Node(iter->val);
            iter->next = dummy;
            dummy->next = front;
            iter = iter->next->next;
        }

//         second step
        iter = head;
        while(iter!=NULL){
            if(iter->random!=NULL)
            iter->next->random = iter->random->next;

            iter = iter->next->next;
        }

//        final step
        iter = head;
        Node* d1 = new Node(0);
        Node* d2 = d1;
        while(iter!= NULL){
            cout << d1->val << " ";
            front = iter->next->next;
            d1->next = iter->next;
            d1 = d1->next;
            iter->next = front;
            iter = front;

        }
        return d2->next;
    }
};