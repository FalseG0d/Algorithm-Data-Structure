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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*next = head->next;

        while(curr != NULL) {
            curr->next = prev;

            prev = curr;
            curr = next;
            if(next) next = next->next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode*half = slow->next;
        if(half == head) return true;

        half = reverseList(half);

        while(half && head) {
            // cout<<head->val<<" "<<half->val<<"\n";
            if(head->val != half->val) return false;

            half = half->next;
            head = head->next;
        }

        return true;
    }
};