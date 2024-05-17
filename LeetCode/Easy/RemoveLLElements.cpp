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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        if(head->next == NULL) {
            if(head->val == val) {
                delete head;
                return NULL;
            } else return head;
        }

        ListNode*prev = head;
        ListNode*curr = head->next;
        ListNode*next = head->next->next;

        while(curr) {
            if(curr->val == val) {
                // Delete curr Node
                prev->next = next;
                delete curr;
            } else {
                prev = curr;
            }

            curr = next;
            if(next) next = next->next;
        }

        if(head->val == val) {
            curr = head;
            head = head->next;
            delete curr;
        }

        return head;
    }
};