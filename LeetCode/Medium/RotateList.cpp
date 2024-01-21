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
    int len(ListNode* head){
        ListNode*itr = head;
        int res = 0;
        
        while(itr){
            itr = itr -> next;
            res++;
        }
        
        return res;
    }
    int getLast(ListNode* head){
        if(head == NULL) return -1000;
        if(head -> next == NULL) return -1000;
        
        ListNode* cur = head;
        ListNode* nxt = head -> next;
        
        while(nxt->next){
            cur = nxt;
            nxt = nxt -> next;
        }
        
        int res = nxt -> val;
        cur -> next = NULL;
        delete(nxt);
        
        return res;
    }

    ListNode* help(ListNode* head, int k){
        if(k == 0) return head;
        
        int val = getLast(head);
        
        if(val == -1000) return head;
        
        ListNode* newHead = new ListNode(val);
        
        newHead -> next = head;
        
        return help(newHead, k - 1);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int l = len(head);
        k %= l;
        
        return help(head, k);
    }
};