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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*>que;
        
        int level = 0;

        que.push(root);

        while(!que.empty()) {
            int N = que.size();
            vector<int>temp;

            for(int i=0;i<N;i++) {
                TreeNode*tempNode = que.front();
                
                que.pop();
                temp.push_back(tempNode->val);
                
                if(tempNode->left) que.push(tempNode->left);
                if(tempNode->right) que.push(tempNode->right);
            }

            if(level % 2 == 1) reverse(temp.begin(), temp.end());

            res.push_back(temp);

            level++;
        }

        return res;
    }
};