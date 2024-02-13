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
    void print(ListNode*head){
        while(head){
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<"\n";
    }
    
    ListNode*mergeList(ListNode*left, ListNode*right){
        ListNode*res = NULL;
        
        // print(left);
        // print(right);
        
        if(left->val < right->val){
            res = left;
            left = left->next;
        } else {
            res = right;
            right = right->next;
        }
        
        ListNode*itr = res;
        
        while(left && right){
            if(left->val < right->val){
                itr->next = left;
                left = left->next;
            }else{
                itr->next = right;
                right = right->next;
            }
            
            itr = itr->next;
        }
        
        while(left){
            itr->next = left;
            
            left = left->next;
            itr = itr->next;
        }
        
        while(right){
            itr->next = right;
            
            right = right->next;
            itr = itr->next;
        }
        
        // print(res);
        
        return res;
    }
    
    ListNode* getMid(ListNode* head){        
        ListNode*slow = head;
        ListNode*fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode*mid = getMid(head);
        
        ListNode*left = head;
        ListNode*right = mid->next;
        mid->next = NULL;
        
        // print(left);
        // print(right);
        
        left = sortList(left);
        right = sortList(right);
        
        return mergeList(left, right);
    }
};