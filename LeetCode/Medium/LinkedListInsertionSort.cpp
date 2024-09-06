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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* res = NULL;
        ListNode* itr = head;

        while(itr) {
            ListNode*tmp = itr->next;

            if(res == NULL) {
                res = itr;
                res->next = NULL;
            } else {
                ListNode*curr = res;
                ListNode*prev = NULL;

                while(curr) {
                    if(curr->val > itr->val) {
                        break;
                    }

                    prev = curr;
                    curr = curr->next;
                }

                if(curr == NULL) {
                    prev->next = itr;
                    itr->next = NULL;
                } else if(prev == NULL) {
                    itr->next = curr;
                    res = itr;
                } else {
                    prev->next = itr;
                    itr->next = curr;
                }
            }

            itr = tmp;
        }

        return res;
    }
};