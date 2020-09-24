/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root,int l,int r,int *res) {
    if(root->val <=r && root->val >=l) (*res)+=root->val;
    if(root->left) dfs(root->left,l,r,res);
    if(root->right)dfs(root->right,l,r,res);
}
int rangeSumBST(struct TreeNode* root, int L, int R){
    int res = 0;
    dfs(root,L,R,&res);
    return res;
}