/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root,int **t_arr,int t_size,int*res) {
    (*t_arr) = (int*)realloc((*t_arr),t_size*sizeof(int));
    (*t_arr)[t_size-1] = root->val;
    if(root->left) dfs(root->left,t_arr,t_size+1,res);
    if(root->right) dfs(root->right,t_arr,t_size+1,res);
    if(!root->left && !root->right) {
        for(int i = 0;i<t_size;i++) {
            (*res)+= (*t_arr)[i] * pow(10,t_size-1-i);
        }
    }
}
int sumNumbers(struct TreeNode* root){
    int res = 0;
    if(!root) return 0;
    int *t_arr = NULL;
    dfs(root,&t_arr,1,&res);
    return res;
}