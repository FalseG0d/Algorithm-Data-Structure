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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode*last;

        queue<TreeNode*>que1;
        queue<TreeNode*>que2;
        
        vector<int>res;
        
        last = root;
        if(root) que1.push(root);

        while(!que1.empty() || !que2.empty()) {
            res.push_back(last->val);

            if(!que1.empty()) {
                while(!que1.empty()) {
                    TreeNode*front = que1.front();
                    que1.pop();

                    if(front->left) {que2.push(front->left);last = front->left;}
                    if(front->right) {que2.push(front->right);last = front->right;}
                }
            } else if(!que2.empty()) {
                while(!que2.empty()) {
                    TreeNode*front = que2.front();
                    que2.pop();

                    if(front->left) {que1.push(front->left);last = front->left;}
                    if(front->right) {que1.push(front->right);last = front->right;}
                }
            }
        }

        return res;
    }
};