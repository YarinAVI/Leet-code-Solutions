/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode * root, int parent,bool *res) {
    if(root->val != parent) {
        (*res)  = false;
        return;
    }
    if(root->left) dfs(root->left,root->val,res);
    if(root->right)dfs(root->right,root->val,res);
}

bool isUnivalTree(struct TreeNode* root){
    bool res = true;
    if(!root) return res;
    dfs(root,root->val,&res);
    return res;
}