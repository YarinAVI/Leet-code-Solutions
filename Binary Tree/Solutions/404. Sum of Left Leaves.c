/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode*root,int *res) {
    if(root->right && root->left) {
        if(!root->left->left && !root->left->right) (*res)+=root->left->val, dfs(root->right,res);
        else dfs(root->right,res),dfs(root->left,res);
    }
    else if(root->right) dfs(root->right,res);
    else if(root->left)  {
        if(!root->left->left && !root->left->right) (*res)+=root->left->val;
        else dfs(root->left,res);
    }
}
int sumOfLeftLeaves(struct TreeNode* root){
int res = 0;
    if(!root) return 0;
    dfs(root,&res);
    return res;
}