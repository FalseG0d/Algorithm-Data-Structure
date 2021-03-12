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
        map<ListNode*,int>mp;
        ListNode*temp=headA;
        
        while(headA!=NULL){
            mp[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL){
            mp[headB]++;
            headB=headB->next;
        }
        
        while(temp!=NULL){
            if(mp[temp]==2)return temp;
            
            temp=temp->next;
        }
        
        return NULL;
    }
};