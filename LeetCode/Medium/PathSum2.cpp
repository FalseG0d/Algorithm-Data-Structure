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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) {
            if(root->val == targetSum) return {{root->val}};
            else return {};
        }
        vector<vector<int>> left = pathSum(root->left, targetSum - root->val);
        vector<vector<int>> right = pathSum(root->right, targetSum - root->val);

        vector<vector<int>> res;
        for(vector<int> tmp : left) {
            tmp.insert(tmp.begin(), root->val);

            res.push_back(tmp);
        }
        for(vector<int> tmp : right) {
            tmp.insert(tmp.begin(), root->val);

            res.push_back(tmp);
        }

        return res;
    }
};