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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>v;
        ListNode*temp=head;
        
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        for(int i=0;i<v.size();i+=k){
            if(i+k-1>=v.size())break;
            
            for(int j=0;j<k/2;j++){
                swap(v[i+j],v[i+k-j-1]);
            }
        }
        
        ListNode*res=new ListNode(v[0]);
        temp=res;
        
        for(int i=1;i<v.size();i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        }
        
        return res;
    }
};