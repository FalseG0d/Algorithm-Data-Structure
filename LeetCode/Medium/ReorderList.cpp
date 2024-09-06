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
    void reorderList(ListNode* head) {
        if(!head->next) return;

        int size = 0;
        ListNode*itr = head;

        while(itr) {
            itr = itr->next;
            size++;
        }

        if(size % 2 == 0) size--;

        ListNode*prev = head;
        ListNode*curr = head->next;

        for(int i=0;i<size/2;i++) {
            prev = curr;
            if(curr) curr = curr->next;
        }

        prev->next = NULL;

        prev = curr;
        curr = curr->next;
        prev->next = NULL;

        while(curr) {
            ListNode*nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        ListNode*itr1 = head;
        ListNode*itr2 = prev;

        prev = NULL;

        while(itr1 && itr2) {
            ListNode*next1 = itr1->next;
            ListNode*next2 = itr2->next;

            itr1->next = itr2;
            itr2->next = next1;

            if(prev) prev->next = itr1;
            
            prev = itr2;

            itr1 = next1;
            itr2 = next2;
        }
    }
};