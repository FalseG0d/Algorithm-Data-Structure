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
    ListNode*reverseLinkedList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        ListNode*prev = NULL;
        ListNode*curr = head;

        while(curr) {
            ListNode*next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseLinkedList(head);
        ListNode*prev = NULL;
        ListNode*curr = head;

        for(int i=1;i<n;i++) {
            prev = curr;
            curr = curr->next;
        }

        if(prev != NULL) prev->next = curr->next;
        else head = curr->next;

        delete curr;

        return reverseLinkedList(head);
    }
};