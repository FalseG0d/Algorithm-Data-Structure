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
    void print(TreeNode*root){
        if(root == NULL) return;
        
        cout<<root->val<<"->";
        
        print(root->left);
        print(root->right);
    }
    
    TreeNode* getRightMost(TreeNode* root){
        if(root->right == NULL) return root;
        else return getRightMost(root->right);
    }
    void flatten(TreeNode* root) {
        
        if(root == NULL) return;
        
        if(root->left == NULL){
            flatten(root->right);
            return;
        }
        
        TreeNode*rightMost = getRightMost(root->left);
        
        rightMost->right = root->right;
        root->right = root->left;
        root->left = NULL;
        
        flatten(root->right);
    }
};