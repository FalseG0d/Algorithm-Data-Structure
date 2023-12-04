/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>s;
        
        int size = 0;
        
        if(root != NULL){
            s.push(root);
            size = 1;
        }
        
        while(!s.empty()){        
            int currSize = 0;
            vector<int>temp;
            
            for(int i=0;i<size;i++){
                TreeNode*curr = s.front();
                s.pop();
                
                temp.push_back(curr->val);
                
                if(curr->left != NULL){
                    s.push(curr->left);
                    currSize++;
                }
                if(curr->right!= NULL){
                    s.push(curr->right);
                    currSize++;
                }
            }
            
            res.push_back(temp);
            size = currSize;
        }
        
        return res;
    }
};