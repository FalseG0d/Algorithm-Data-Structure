/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* convert(vector<int>&v, int beg, int end){
        if(beg > end) return NULL;
        if(beg == end) return new TreeNode(v[end]);
        
        int itr = (beg + end)/2;
        TreeNode*res = new TreeNode(v[itr]);
        
        res->left = convert(v, beg, itr-1);
        res->right= convert(v, itr+1, end);
        
        return res;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        
        ListNode*itr = head;
        
        while(itr!=NULL){
            v.push_back(itr->val);
            
            itr = itr->next;
        }
        
        int N = v.size();
        
        return convert(v, 0, N-1);
    }
};