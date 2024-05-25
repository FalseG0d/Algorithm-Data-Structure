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
    void help(TreeNode* root) {
        if(root == NULL) return;

        TreeNode*left = root->left;
        TreeNode*right = root->right;

        root->left = right;
        root->right = left;

        help(root->left);
        help(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        help(root);

        return root;
    }
};