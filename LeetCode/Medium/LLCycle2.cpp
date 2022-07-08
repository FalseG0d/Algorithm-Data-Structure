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
        ListNode*hare = head;
        ListNode*tortoise = head;
        
        while(hare != NULL && tortoise != NULL){
            hare = hare->next;
            if(hare) hare = hare->next;
            tortoise = tortoise->next;
            
            if(hare == tortoise) break;
        }
        
        if(hare == NULL) return NULL;
        
        tortoise = head;
        
        while(tortoise != hare){
            tortoise = tortoise->next;
            hare = hare->next;
        }
        
        return hare;
    }
};