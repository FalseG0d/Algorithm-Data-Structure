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
        if(!head) return head;

        Node*itr = head;

        while(itr) {
            Node*next = itr->next;
            Node*newItr = new Node(itr->val);

            itr->next = newItr;
            newItr->next = next;

            itr = next;
        }

        itr = head;

        while(itr) {
            Node*next = itr->next->next;
            itr->next->random = itr->random ? itr->random->next : NULL;
            
            itr = next;
        }

        itr = head;
        Node*res = head->next;

        while(itr) {
            Node*next = itr->next->next;
            itr->next->next = next ? next->next : NULL;
            itr->next = next;
            itr = next;
        }

        return res;
    }
};