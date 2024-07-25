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
    vector<TreeNode*> help(int beg, int end) {
        if(beg > end) return {NULL};
        if(beg == end) return {new TreeNode(beg)};

        vector<TreeNode*> res;

        for(int i=beg;i<=end;i++) {
            vector<TreeNode*>lefts = help(beg, i-1);
            vector<TreeNode*>rights = help(i+1, end);

            for(TreeNode*left : lefts) {
                for(TreeNode*right : rights) {
                    TreeNode*root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    res.push_back(root);
                }
            }
        }

        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return help(1, n);
    }
};