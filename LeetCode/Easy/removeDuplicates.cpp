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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*prev = NULL;
        ListNode*itr = head;

        while(itr) {
            if(prev && prev->val == itr->val) {
                ListNode*toDel = itr;
                prev->next = itr->next;
                itr = itr->next;
                
                delete toDel;
            } else {
                prev = itr;
                itr = itr->next;
            }
        }

        return head;
    }
};