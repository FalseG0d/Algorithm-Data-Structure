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
    string preOrder(TreeNode* root) {
        if(root == NULL) return "X";

        return to_string(root->val) + preOrder(root->left) + preOrder(root->right);
    }
    
    string postOrder(TreeNode* root) {
        if(root == NULL) return "X";

        return postOrder(root->left) + postOrder(root->right) + to_string(root->val);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string preOrderStr = preOrder(root);
        string preOrderPtr = preOrder(subRoot);
        
        string postOrderStr = postOrder(root);
        string postOrderPtr = postOrder(subRoot);

        int findPre = preOrderStr.find(preOrderPtr);
        int findPost = postOrderStr.find(postOrderPtr);

        // cout<<preOrderStr<<" "<<preOrderPtr<<"\n";
        // cout<<postOrderStr<<" "<<postOrderPtr;
        // cout<<findPre<<" "<<findPost;

        return findPre != -1 && findPost != -1;
    }
};