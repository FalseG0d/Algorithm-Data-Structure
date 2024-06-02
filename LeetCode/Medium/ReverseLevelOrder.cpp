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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};

    vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int N = que.size();
            vector<int>temp;

            for(int i=0;i<N;i++) {
                TreeNode*front = que.front();
                que.pop();

                temp.push_back(front->val);
                
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};