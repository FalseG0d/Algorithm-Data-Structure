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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*leftNode = NULL;
        ListNode*rightNode = NULL;

        ListNode*leftNodePrev = NULL;
        ListNode*rightNodeNext = NULL;

        ListNode*prev = NULL;
        ListNode*curr = head;

        int itr = 1;
        while(curr && itr <= right+1) {
            if(itr == left-1) leftNodePrev = curr;
            if(itr == left) leftNode = curr;
            if(itr == right) rightNode = curr;
            if(itr == right+1) rightNodeNext = curr;

            itr++;
            curr = curr->next;
        }

        if(rightNode) rightNode->next = NULL;

        curr = leftNode;
        prev = NULL;

        while(curr) {
            ListNode*next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }

        if(leftNodePrev) leftNodePrev->next = rightNode;
        if(leftNode) leftNode->next = rightNodeNext;

        if(leftNode == head) return rightNode;
        else return head;
    }
};