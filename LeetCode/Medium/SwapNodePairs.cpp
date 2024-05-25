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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*next = head->next;

        while(curr && next) {
            ListNode*dat = next->next;

            if(prev) prev->next = next;
            else head = next;

            next->next = curr;
            curr->next = dat;

            prev = curr;
            curr = dat;
            if(dat) next = dat->next;
        }

        return head;
    }
};