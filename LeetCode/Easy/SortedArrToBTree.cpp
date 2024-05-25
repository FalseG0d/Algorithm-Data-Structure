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
    TreeNode* help(vector<int>& nums, int beg, int end) {
        if(beg > end) return NULL;

        int curr = beg + (end - beg) / 2;
        
        TreeNode* res = new TreeNode(nums[curr]);
        res->left = help(nums, beg, curr-1);
        res->right = help(nums, curr+1, end);

        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int N = nums.size();

        return help(nums, 0, N-1);
    }
};