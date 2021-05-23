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
//time complexity is o(n) but space complexity is o(n) due to hash map used.
class Solution {
public:
    Node* copyRandomList(Node* head) {
      Node* copy1 = head;
        Node* copy2 = NULL;
        unordered_map<Node*,Node*> mp;
        while(copy1!=NULL){
            copy2 = new Node(copy1->val);
            mp[copy1] = copy2;
            copy1 = copy1->next;
        }
        copy1 = head;
        // copy1 = copy1->next;
        while(copy1!=NULL){
            copy2 = mp[copy1];
            copy2->next = mp[copy1->next];
            copy2->random = mp[copy1->random];
            copy1 = copy1->next;
        }
        Node* pp = new Node(0);
        pp->next = mp[head];
        return  pp->next;


        // return
    }
};