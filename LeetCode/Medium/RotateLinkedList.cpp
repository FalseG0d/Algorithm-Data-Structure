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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int N = 0;
        ListNode*itr = head;

        while(itr->next != NULL) {
            itr = itr->next;
            N++;
        }

        k %= (N+1);
        itr->next = head;

        itr = head;

        for(int i=0;i<N-k;i++) itr = itr->next;

        ListNode*res = itr->next;
        itr->next = NULL;

        return res;
    }
};