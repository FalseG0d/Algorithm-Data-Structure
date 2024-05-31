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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> res(2, NULL);

        if(root == NULL) return res;

        if(root->val <= target) {
            // Add to Smaller
            res[0] = root;

            vector<TreeNode*>check = splitBST(root->right, target);
            root->right = check[0];

            res[1] = check[1];
        } else {
            // Add to Greater
            res[1] = root;

            vector<TreeNode*>check = splitBST(root->left, target);
            root->left = check[1];

            res[0] = check[0];
        }

        return res;
    }
};