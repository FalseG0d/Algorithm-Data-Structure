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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        
        if(p == NULL) return false;
        if(q == NULL) return false;
        
        queue<TreeNode*>pQue;
        queue<TreeNode*>qQue;
        
        pQue.push(p);
        qQue.push(q);

        while(!pQue.empty() && !qQue.empty()) {
            TreeNode*pTop = pQue.front();
            TreeNode*qTop = qQue.front();
            
            if(pTop == NULL && qTop == NULL) {
                pQue.pop();
                qQue.pop();

                continue;
            }
            else if(pTop == NULL) break;
            else if(qTop == NULL) break;

            if(pTop->val != qTop->val) break;
            
            pQue.pop();
            qQue.pop();
            
            
            pQue.push(pTop->left);
            qQue.push(qTop->left);
            
            pQue.push(pTop->right);
            qQue.push(qTop->right);
        }

        return pQue.size() == 0 && qQue.size() == 0;
    }
};