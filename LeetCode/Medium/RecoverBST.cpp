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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);

        if(root->val < prev->val) {
            if(!first && !middle) {
                first = root;
                middle = prev;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(last) swap(middle->val, last->val);
        else swap(middle->val, first->val);
    }
};