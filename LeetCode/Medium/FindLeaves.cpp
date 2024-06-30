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
    int getTreeHeight(TreeNode* root) {
        if(root == NULL) return 0;

        return 1 + max(
            getTreeHeight(root->left),
            getTreeHeight(root->right)
        );
    }
    int help(TreeNode* root, vector<vector<int>>& res) {
        if(root == NULL) return 0;

        int level = max(
            help(root->left, res),
            help(root->right, res)
        );

        res[level].push_back(root->val);

        return level + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        int N = getTreeHeight(root);
        vector<vector<int>> res(N, vector<int>());

        help(root, res);

        return res;
    }
};