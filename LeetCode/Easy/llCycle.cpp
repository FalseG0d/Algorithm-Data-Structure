class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>mp;
        
        while(head!=NULL){
            mp[head]++;
            if(mp[head]>1)return true;
            head=head->next;
        }
        
        return false;
    }
};