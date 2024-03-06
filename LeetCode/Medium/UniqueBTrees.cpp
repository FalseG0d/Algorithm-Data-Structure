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
    vector<TreeNode*> help(int left, int right){
        vector<TreeNode*> res;
        
        if(left == right)return {new TreeNode(left)};
        if(left > right) return {NULL};
        
        for(int i=left;i<=right;i++){
            vector<TreeNode*>leftNodes   = help(left,i-1);
            vector<TreeNode*>rightNodes  = help(i+1,right);
            
            for(TreeNode*leftNode:leftNodes){
                for(TreeNode*rightNode:rightNodes){
                    res.push_back(new TreeNode(i,leftNode,rightNode));
                }
            }
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = help(1,n);
        
        return res;
    }
};