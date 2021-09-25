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
        ListNode*res = NULL;
        ListNode*end = NULL;
        
        map<int,int>mp;
        
        for(auto itr=head;itr!=NULL;itr=itr->next){
            int temp = itr->val;
            mp[temp]++;
        }
        
        for(auto itr=mp.begin();itr!=mp.end();++itr){
            if(itr->second == 1){
                if(res == NULL){
                    res  = new ListNode(itr->first);
                    end = res;
                }
                else {
                    end->next = new ListNode(itr->first);
                    end = end->next;
                }
            }
        }
        
        return res;
    }
};