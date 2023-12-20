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
    ListNode* partition(ListNode* head, int x) {
        vector<int>lesser;
        vector<int>greater;
        
        for(ListNode*itr=head;itr!=NULL;itr=itr->next){
            if(itr->val < x) lesser.push_back(itr->val);
            else greater.push_back(itr->val);
        }
        
        auto itr = head;
        
        for(int ele:lesser){
            itr->val = ele;            
            itr = itr -> next;
        }
        for(int ele:greater){
            itr->val = ele;            
            itr = itr -> next;
        }
        
        return head;
    }
};