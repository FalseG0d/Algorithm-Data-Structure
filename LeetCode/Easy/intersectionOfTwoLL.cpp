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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*itrA = headA;
        ListNode*itrB = headB;
        
        while(itrA) {
            itrA->val = -itrA->val;
            itrA = itrA->next;
        }
        
        ListNode*res = NULL;

        while(itrB) {
            if(itrB->val < 0) {
                res = itrB;
                break;
            }

            itrB = itrB->next;
        }

        itrA = headA;
        
        while(itrA) {
            itrA->val = -itrA->val;
            itrA = itrA->next;
        }

        return res;
    }
};