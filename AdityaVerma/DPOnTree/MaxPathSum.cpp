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
    int res = INT_MIN;
    int solve(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        
        int leftPathSum = solve(root->left);
        int rightPathSum = solve(root->right);
        
        int decNode = root->val;
        if(leftPathSum > 0) decNode += leftPathSum;
        if(rightPathSum > 0) decNode += rightPathSum;
        
        int notDece = root->val;        
        if(leftPathSum > 0 || rightPathSum > 0) notDece += max(leftPathSum,rightPathSum);
        
        res = max(decNode,res);
        
        return notDece;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        solve(root);
        return res;
    }
};