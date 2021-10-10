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
    map<int,int>find;
    TreeNode* help(vector<int>& preorder, int &curr, vector<int>& inorder, int beg, int end){
        if(beg > end) return NULL;
        
        int val = preorder[curr];
        curr++;
        
        TreeNode*root = new TreeNode(val);        
        int pos = find[val];
        
        root->left = help(preorder, curr, inorder, beg, pos - 1);
        root->right= help(preorder, curr, inorder, pos + 1, end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            find[inorder[i]] = i;
        }
        
        int curr = 0;
        
        return help(preorder, curr, inorder, 0, inorder.size() - 1);
    }
};