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
    int ans;
    int inOrder(TreeNode* root, int&k){
        if(root == NULL) return 0;
        if(k == 0) return 0;
        
        inOrder(root->left, k);
        
        k--;
        if(k == 0) ans = root->val;
        
        
        inOrder(root->right, k);
        
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        // cout<<"\n";
        return ans;
    }
};