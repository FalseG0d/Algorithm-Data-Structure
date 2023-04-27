/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        unordered_map<Node*,Node*>mp;
        
        Node*res = new Node(head->val);
        Node*itr = head->next;
        
        mp[head] = res;
        
        Node*prev = res;
        
        while(itr != NULL){
            Node*curr = new Node(itr->val);
            mp[itr] = curr;
            
            prev->next = curr;
            prev = curr;
            itr = itr->next;
        }
        
        itr = head;
        
        while(itr != NULL){
            if(itr->random == NULL) mp[itr]->random = NULL;
            else mp[itr]->random = mp[itr->random];
            
            itr = itr->next;
        }
        
        return res;
    }
};