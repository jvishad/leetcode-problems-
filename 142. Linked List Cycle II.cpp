/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* additional = head;
        ListNode* fast = head;
        ListNode* slow  = head;
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL || fast->next == NULL){
                return NULL;
            }
            if(slow == fast){
                break;
            }
        }
        while(additional!=slow){
            additional = additional->next;
            slow = slow->next;
        }
        return slow;

    }
};