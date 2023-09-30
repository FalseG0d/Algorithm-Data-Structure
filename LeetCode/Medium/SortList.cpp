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
    int getSize(ListNode*head){
        if(head == NULL) return 0;
        
        int res = 0;
        
        while(head){
            res++;            
            head = head->next;
        }
        
        return res;
    }
    
    ListNode* getList(vector<int> v){
        if(v.size() == 0) return NULL;
        
        ListNode*res = new ListNode(v[0]);
        ListNode*itr = res;
        
        for(int i=1;i<v.size();i++){
            itr->next = new ListNode(v[i]);
            itr = itr->next;
        }
        
        return res;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        
        int N = getSize(head);
        
        vector<int>v(N, 0);
        int itr = 0;
        
        while(head != NULL){
            v[itr] = head->val;
            itr++;
            head = head->next;
        }
        
        sort(v.begin(), v.end());
        
        ListNode*res = getList(v);
        
        return res;
    }
};