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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode*next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        ListNode*curr = head;
        ListNode*prev = NULL;
        int carry = 0;

        while(curr) {
            int val = carry + curr->val * 2;
            carry = val / 10;
            val %= 10;

            curr->val = val;

            prev = curr;
            curr = curr->next;
        }

        head = reverse(head);

        if(carry > 0) {
            ListNode*newHead = new ListNode(carry);
            newHead->next = head;

            head = newHead;
        }

        return head;
    }
};