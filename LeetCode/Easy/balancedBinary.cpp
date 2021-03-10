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
    
    int getHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        
        int heightL = getHeight(root->left);
        int heightR = getHeight(root->right);
        
        if (abs(heightL - heightR) > 1)
            return false;
        
        return true;
        
        
    }
};