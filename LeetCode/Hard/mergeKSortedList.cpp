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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        vector<int>temp;
        
        for(ListNode*ele:lists){
            while(ele!=NULL){
                temp.push_back(ele->val);
                // cout<<ele->val<<" ";
                ele=ele->next;
            }//cout<<"\n";
        }
        
        if(temp.size()==0)return NULL;
        
        sort(temp.begin(),temp.end());
        
        ListNode*res=new ListNode(temp[0]);
        ListNode*ret=res;
        
        for(int i=1;i<temp.size();i++){
            res->next=new ListNode(temp[i]);
            res=res->next;
        }
        
        return ret;
    }
};