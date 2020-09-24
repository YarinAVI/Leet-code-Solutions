/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root,int **inorder_arr,int *size_arr) {
    if(root->left) dfs(root->left,inorder_arr,size_arr);
    
    (*inorder_arr) = (int*)realloc((*inorder_arr),++(*size_arr)*sizeof(int));
    (*inorder_arr)[(*size_arr)-1] = root->val;

    if(root->right) dfs(root->right,inorder_arr,size_arr);
}
int minDiffInBST(struct TreeNode* root){
   int res=INT_MAX;
    if(!root) return res;
    int *inorder_arr = 0;
    int size_arr=0;
    dfs(root,&inorder_arr,&size_arr);
    int i;
    for(i=0;i<size_arr-1;i++) if(res>inorder_arr[i+1]-inorder_arr[i]) res =inorder_arr[i+1]-inorder_arr[i];
    return res;
}