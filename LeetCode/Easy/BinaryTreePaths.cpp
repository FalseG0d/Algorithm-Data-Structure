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
    vector<string>res;
    
    void help(TreeNode* root, string path){
        if(root == NULL) return;
        
        stringstream ss;
        ss<<root->val;
        
        if(root->left == NULL && root->right == NULL){
            res.push_back(path + ss.str());
            
            return;
        }
        
        path += ss.str() + "->";
        
        help(root->left, path);
        help(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        help(root, "");        
        
        return res;
    }
};