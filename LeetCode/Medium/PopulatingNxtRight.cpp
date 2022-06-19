/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que1;
        queue<Node*> que2;
        
        if(root) que1.push(root);
        
        while(!que1.empty() || !que2.empty()){
//             Node*prev = NULL;
            
//             if(!que1.empty()){
//                 prev = que1.front();
//                 que1.pop();
                
//                 if(prev->left) que2.push(prev->left);
//                 if(prev->right) que2.push(prev->right);
//             }else{
//                 prev = que2.front();
//                 que2.pop();
                
//                 if(prev->left) que1.push(prev->left);
//                 if(prev->right) que1.push(prev->right);
//             }
            
//             prev->next = NULL;
            
//             
            Node*prev = NULL;
            
            while(!que1.empty()){
                Node*front = que1.front();
                que1.pop();
                
                if(prev) prev->next = front;
                front->next = NULL;
                prev = front;
                
                if(front->left) que2.push(front->left);
                if(front->right) que2.push(front->right);
            }
            
            prev = NULL;
            
            while(!que2.empty()){
                Node*front = que2.front();
                que2.pop();
                
                if(prev) prev->next = front;
                front->next = NULL;
                prev = front;
                
                if(front->left) que1.push(front->left);
                if(front->right) que1.push(front->right);
            }
        }
        
        return root;
    }
};