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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode*itr1 = NULL;
        ListNode*itr2 = NULL;

        if(list1->val < list2->val) {
            itr1 = list1;
            itr2 = list2;
        } else {
            itr1 = list2;
            itr2 = list1;
        }

        ListNode*res = itr1;
        ListNode*prev = itr1;
        itr1 = itr1->next;

        while(itr1 && itr2) {
            if(itr1->val <= itr2->val) {
                prev = itr1;
                itr1 = itr1->next;
            } else {
                prev->next = itr2;
                prev = itr2;
                ListNode*nextItr2 = itr2->next;
                itr2->next = itr1;
                itr2 = nextItr2;
            }
        }

        if(itr2) prev->next = itr2;

        return res;
    }
};