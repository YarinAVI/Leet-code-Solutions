/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs (struct TreeNode* root,int max,int *res) {
    if(root->val >=max) (*res)++,max = root->val;
    if(root->left) dfs(root->left,max,res);
    if(root->right) dfs(root->right,max,res);
}

int goodNodes(struct TreeNode* root){
    int res = 0;
    if(!root) return res;
    dfs(root,INT_MIN,&res);
    return res;
}