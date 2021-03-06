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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*res=new ListNode();
        ListNode*result=res;
        
        ListNode*a=l1,*b=l2;
        int carry=0;
        
        while(a!=NULL||b!=NULL){
            int x=a!=NULL?a->val:0;
            int y=b!=NULL?b->val:0;
            
            int temp=x+y+carry;
            carry=temp/10;
            temp%=10;
            
            res->val=temp;
            
            a=a!=NULL?a->next:a;
            b=b!=NULL?b->next:b;
            
            if(a!=NULL||b!=NULL){
                res->next=new ListNode();
                res=res->next;
                }
            // cout<<temp<<"\n";
        }
        if(carry>0)res->next=new ListNode(carry);
        
        return result;
    }
};