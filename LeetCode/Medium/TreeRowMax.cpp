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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};

        vector<int>res;
        queue<TreeNode*>que;
        
        que.push(root);

        while(!que.empty()) {
            int N = que.size();
            int rowMax = INT_MIN;

            for(int i=0;i<N;i++) {
                TreeNode*front = que.front();
                que.pop();

                rowMax = max(rowMax, front->val);
                
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }

            res.push_back(rowMax);
        }

        return res;
    }
};