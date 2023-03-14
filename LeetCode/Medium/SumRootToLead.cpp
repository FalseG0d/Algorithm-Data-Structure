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
    int dfs(TreeNode* root, int parent) {
        if(root->left == NULL && root->right == NULL) return parent * 10 + root->val;
        
        int curr = root->val + 10 * parent;
        
        int left = 0;
        int right = 0;
        
        if(root->left) left = dfs(root->left, curr);
        if(root->right) right = dfs(root->right, curr);
        
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};