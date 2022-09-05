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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int>res;
        queue<TreeNode*>que;
        
        que.push(root);
        
        while(!que.empty()){
            int N = que.size();
            
            while(N > 0){
                TreeNode*curr = que.front();
                que.pop();
                
                if(N == 1) res.push_back(curr->val);
                
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
                
                N--;
            }
        }
        
        return res;
    }
};