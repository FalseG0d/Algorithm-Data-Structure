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
    int count(ListNode*head){
        if(head == NULL) return 0;
        
        return 1 + count(head -> next);
    }
    
    void help(ListNode* head, int n){
        if(n == 0){
            ListNode* toDel = head -> next;
            head -> next = toDel -> next;

            delete(toDel);
        }else{
            help(head -> next, n - 1);
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = count(head);
        
        if(c == n){
            ListNode*toDel = head;
            ListNode*res = head -> next;
            
            delete(toDel);
            return res;
        }
        
        help(head, c - n - 1);
        
        return head;
    }
};