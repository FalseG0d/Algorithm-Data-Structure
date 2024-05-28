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
    ListNode* partition(ListNode* head, int x) {
        ListNode*smallHead = NULL;
        ListNode*largeHead = NULL;
        
        ListNode*smallItr = NULL;
        ListNode*largeItr = NULL;

        ListNode*itr = head;

        while(itr) {
            if(itr->val < x) {
                if(smallItr == NULL) smallHead = smallItr = itr;
                else {
                    smallItr->next = itr;
                    smallItr = itr;
                    }
            } else {
                if(largeItr == NULL) largeHead = largeItr = itr;
                else {
                    largeItr->next = itr;
                    largeItr = itr;
                    }
            }

            itr = itr->next;
        }

        if(smallItr) smallItr->next = NULL;
        if(largeItr) largeItr->next = NULL;

        ListNode*res = NULL;

        if(smallHead) {
            res = smallHead;
            if(largeHead) smallItr->next = largeHead;
        }
        else res = largeHead;

        return res;
    }
};