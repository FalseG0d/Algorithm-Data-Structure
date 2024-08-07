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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode*begOdd = NULL;
        ListNode*begEve = NULL;

        ListNode*endOdd = NULL;
        ListNode*endEve = NULL;

        int cnt = 0;
        ListNode*itr = head;

        while(itr != NULL) {
            if(cnt % 2 == 0) {
                // Even Node

                if(begEve == NULL) {
                    begEve = endEve = itr;
                } else {
                    endEve->next = itr;
                    endEve = itr;
                }
            } else {
                // Odd Node

                if(begOdd == NULL) {
                    begOdd = endOdd = itr;
                } else {
                    endOdd->next = itr;
                    endOdd = itr;
                }
            }

            cnt++;
            itr = itr->next;
        }

        if(endEve) endEve->next = NULL;
        if(endOdd) endOdd->next = NULL;

        endEve->next = begOdd;

        return begEve;
    }
};