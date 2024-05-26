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
    map<int,int> freq;
    void helper(TreeNode *node)
    {
        if(!node) return;
        freq[node->val] ++;
        helper(node->left);
        helper(node->right);
        return ;

    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxFreq = 0;
        helper(root);

        for(auto key : freq)
            maxFreq = max(maxFreq, key.second);
            
        for(auto x : freq)
            if(x.second == maxFreq)
                res.push_back(x.first);
        return res;
    }
};