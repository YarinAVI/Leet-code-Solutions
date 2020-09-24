/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root,int cur_num,int *res) {
    cur_num = cur_num << 1;
    cur_num = cur_num | root->val;
    
    if(root->left) dfs(root->left,cur_num,res);
    if(root->right) dfs(root->right,cur_num,res);
    
    if(!root->left && !root->right) {
        (*res)+=cur_num;
    }
}
int sumRootToLeaf(struct TreeNode* root){
    int res = 0;
    if(!root) return res;
    bool *arr = NULL;
    int cur_number = 0;
    dfs(root,cur_number,&res);
    return res;
}