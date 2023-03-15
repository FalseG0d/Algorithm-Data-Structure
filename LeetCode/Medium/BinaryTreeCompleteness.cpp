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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        
        bool flag = true;
        
        while(!que.empty()){
            TreeNode*temp = que.front();
            que.pop();
            
            if(temp == NULL) flag = false;
            else{
                if(!flag) return false;
                else{
                    que.push(temp->left);
                    que.push(temp->right);
                }
            }
        }
        
        return true;
    }
};