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
        queue<TreeNode*>que;
        vector<vector<int>>res;
        vector<int>temp;
        
        int level = 0;
        int size = 0;
        
        if(root != NULL){
            que.push(root);
            size = 1;
        }
        
        while(!que.empty()){
            TreeNode*top = que.front();
            
            if(top->left != NULL) que.push(top->left);
            if(top->right != NULL)que.push(top->right);
            
            temp.push_back(top->val);
            que.pop();

            size--;
            
            
            if(size == 0){
                if(level % 2 == 1) reverse(temp.begin(),temp.end());
                
                res.push_back(temp);
                temp.clear();
                
                size = que.size();
                level++;
            }
        }
        
        return res;
    }
};