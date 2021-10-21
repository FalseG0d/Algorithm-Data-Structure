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
    int help(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        
        int l = max(0, help(root->left, ans));
        int r = max(0, help(root->right, ans));
        
        ans = max(ans, root->val + l + r);
        
        int res = max(l, r);
        res = max(res, 0);
        
        return root->val + res;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        int ans = root->val;
        int temp = help(root, ans);
        
        // for(auto itr=mp.begin();itr!=mp.end();++itr){
        //     cout<<itr->first->val<<" : "<<itr->second<<"\n";
        // }
        
        return ans;
    }
};