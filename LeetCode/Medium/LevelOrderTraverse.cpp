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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        queue<TreeNode*>que1;
        queue<TreeNode*>que2;

        if(root) que1.push(root);

        while(!que1.empty() || !que2.empty()) {
            vector<int>temp;
            while(!que1.empty()) {
                TreeNode* top = que1.front();
                que1.pop();

                temp.push_back(top->val);

                if(top->left) que2.push(top->left);
                if(top->right) que2.push(top->right);
            }

            if(temp.size() > 0) res.push_back(temp);
            temp.clear();
            while(!que2.empty()) {
                TreeNode* top = que2.front();
                que2.pop();

                temp.push_back(top->val);

                if(top->left) que1.push(top->left);
                if(top->right) que1.push(top->right);
            }
            if(temp.size() > 0) res.push_back(temp);
        }

        return res;
    }
};