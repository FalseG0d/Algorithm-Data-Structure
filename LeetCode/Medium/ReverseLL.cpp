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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode*itr=head;
        while(itr){
            v.push_back(itr->val);
            itr=itr->next;
        }
        
        reverse(v.begin()+left-1,v.begin()+right);
        
        itr=head;
        int i=0;
        
        while(itr){
            itr->val = v[i++];
            itr=itr->next;
        }
        
        return head;
    }
};