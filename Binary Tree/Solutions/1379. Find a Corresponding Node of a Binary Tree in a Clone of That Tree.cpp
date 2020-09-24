/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        TreeNode * res = nullptr;
        dfs(cloned,target->val,&res);
        return res;
    }
    void dfs(TreeNode* root,int target,TreeNode**p_res) {
            if(root->left) {
                if(root->left->val==target) {
                    (*p_res) = root->left;
                    return;
                }
                else dfs(root->left,target,p_res);
            } 
            if(root->right) {
                if(root->right->val==target) {
                    (*p_res) = root->right;
                    return;
                }
                else dfs(root->right,target,p_res);
            }
            if(root->val == target) (*p_res) = root;
    }
};