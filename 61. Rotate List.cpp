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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0){
            return head;
        }
        if(head == NULL){
            return head;
        }
        int len = 1;
        ListNode* start = head,*rem = head,*np = head;
        while(start->next!= NULL){
            start = start->next;
            len++;
        }
        start->next = np;
        int it = len - (k%len);
        int i=0;
        while(i < it){
            start = start->next;
            i++;
        }
        head = start->next;
        start->next = NULL;
        // cout << len;
        return head;
    }
};