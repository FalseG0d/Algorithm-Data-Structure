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
    TreeNode *build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
    {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;

        root->left = build(postorder, postStart, postStart + numLeft - 1, inorder, inStart, inRoot - 1, mp);
        root->right = build(postorder, postStart + numLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mp);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // at first, we make a map for inorder for the index, to check the position of left subtree and right subtree
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode *root = build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }
};