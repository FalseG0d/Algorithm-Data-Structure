class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*hare = head;
        ListNode*tort = head;

        while(hare != NULL) {
            hare = hare->next;
            tort = tort->next;

            if(hare == NULL) break;
            else hare = hare->next;

            if(hare == tort) return true;
        }

        return false;
    }
};
