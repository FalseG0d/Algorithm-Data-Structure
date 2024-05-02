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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*itr1 = l1;
        ListNode*itr2 = l2;

        int val = itr1->val + itr2->val;
        int car = val / 10;

        val %= 10;

        ListNode*res = new ListNode(val);
        ListNode*pre = res;

        itr1 = itr1->next;
        itr2 = itr2->next;

        while(itr1 && itr2) {
            val = itr1->val + itr2->val + car;
            car = val / 10;
            val %= 10;

            pre->next = new ListNode(val);

            itr1 = itr1->next;
            itr2 = itr2->next;
            pre = pre->next;
        }

        while(itr1) {
            val = itr1->val + car;
            car = val / 10;
            val %= 10;

            pre->next = new ListNode(val);

            itr1 = itr1->next;
            pre = pre->next;
        }

        while(itr2) {
            val = itr2->val + car;
            car = val / 10;
            val %= 10;

            pre->next = new ListNode(val);

            itr2 = itr2->next;
            pre = pre->next;
        }

        if(car > 0) pre->next = new ListNode(car);
        
        return res;
    }
};