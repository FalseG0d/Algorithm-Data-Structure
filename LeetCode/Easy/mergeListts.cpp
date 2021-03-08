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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)return NULL;
        
        vector<int>v;
        
        while(l1!=NULL){
            int x=l1->val;
            l1=l1->next;
            
            v.push_back(x);
        }
        while(l2!=NULL){
            int x=l2->val;
            l2=l2->next;
            
            v.push_back(x);
        }
        
        sort(v.begin(),v.end());
        
        ListNode*head=new ListNode(v[0]);
        ListNode*temp=head;
        
        for(int i=1;i<v.size();i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        }cout<<"\n";
        
        return head;
    }
};