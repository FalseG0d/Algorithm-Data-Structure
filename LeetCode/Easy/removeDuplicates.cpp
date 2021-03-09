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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp=head;
        
        while(temp!=NULL){
            ListNode*first=temp;
            ListNode*second=temp->next;
            
            if(second==NULL)break;
            
            int a=first->val,b=second->val;
            
            if(a==b){
                first->next=second->next;
                
                delete second;
            }
            
            first=temp;
            second=temp->next;
            
            if(second==NULL)break;
            
            if(first->val!=second->val)
                temp=temp->next;
        }
        
        return head;
    }
};