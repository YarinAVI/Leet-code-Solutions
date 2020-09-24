/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int *a,int *b) {
    if((*a)>(*b)) return *a;
    return *b;
}
void dfs(struct TreeNode* root,int *res) {
    
    if(root->left && root->right) {
        (*res)++;
        int x = (*res);
        dfs(root->left,res);
        dfs(root->right,&x);
        (*res) = max(&x,res);
    }
    else if(root->right)(*res)++, dfs(root->right,res);
    else if(root->left)(*res)++, dfs(root->left,res);
}

int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    int res=1;
    dfs(root,&res);
    return res;
}