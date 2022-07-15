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
    void print(ListNode* head){
        while(head != NULL){
            cout<<head->val<<"->";
            head = head->next;
        }
        
        cout<<"\n";
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode*resHead = new ListNode(head->val);
        ListNode*resTail = resHead;
        ListNode*itr = head->next;
        
        while(itr != NULL){
            // print(resHead);
            
            if(itr->val < resHead->val){
                ListNode*temp = new ListNode(itr->val);
                temp->next = resHead;
                resHead = temp;
            }else if(itr->val > resTail->val){
                ListNode*temp = new ListNode(itr->val);
                resTail->next = temp;
                resTail = temp;
            }else{
                ListNode*resItr = resHead;
                
                while(resItr->next != NULL){
                    if(resItr->next->val > itr->val){
                        ListNode*temp = new ListNode(itr->val);
                        temp->next = resItr->next;
                        resItr->next = temp;
                        
                        break;
                    }
                    
                    resItr = resItr->next;
                }
                
                if(resItr->next == NULL) resItr->next = new ListNode(itr->val);
            }
            
            itr = itr->next;
        }
        
        return resHead;
    }
};