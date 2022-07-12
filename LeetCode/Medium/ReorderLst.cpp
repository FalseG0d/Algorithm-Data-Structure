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
    ListNode*reverse(ListNode* itr){
        ListNode*prev = itr;
        itr = itr->next;
        ListNode*next = itr->next;
        
        prev->next = NULL;
        
        while(next != NULL){
            itr->next = prev;
            
            prev = itr;
            itr = next;
            next = next->next;
        }
        
        itr->next = prev;
        // prev->next = NULL;
        
        return itr;
    }
    void print(ListNode*itr){
        while(itr != NULL){
            cout<<itr->val<<"->";
            itr = itr->next;
        }
        cout<<"\n";
    }
    void reorderList(ListNode* head) {
        int N = 0;
        ListNode*itr = head;
        
        while(itr != NULL){
            N++;
            itr = itr->next;
        }
        
        if(N == 2 || N == 1) return;
        
        ListNode*itr1 = head;
        ListNode*itr2 = head;
        
        for(int i=0;i<N/2-1;i++) itr2 = itr2->next;
        
        ListNode*temp = itr2->next;
        itr2->next = NULL;
        itr2 = temp;
        
        itr2 = reverse(itr2);
        
        while(itr1 != NULL && itr2 != NULL){
            ListNode*temp1 = itr1->next;
            ListNode*temp2 = itr2->next;
            
            itr1->next = itr2;
            if(temp1) itr2->next = temp1;
            
            itr2 = temp2;
            itr1 = temp1;
        }
        
    }
};