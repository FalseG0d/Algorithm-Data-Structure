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
    int help(TreeNode* root, int parent) {
        if(root == NULL) return 0;

        int curr = parent * 10 + root->val;
        
        if(root->left == NULL && root->right == NULL) return curr;
        
        int res = 0;

        res += help(root->left, curr);
        res += help(root->right, curr);

        return res;
    }
    int sumNumbers(TreeNode* root) {
        return help(root, 0);
    }
};