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
    void help(ListNode* head){
        if(head == NULL) return;
        
        ListNode* curr = head;
        ListNode* next = head -> next;
        if(next == NULL) return;
        help(next -> next);
        int temp = curr -> val;
        curr -> val = next -> val;
        next -> val = temp;
    }
    ListNode* swapPairs(ListNode* head) {
        help(head);
        
        return head;
    }
};