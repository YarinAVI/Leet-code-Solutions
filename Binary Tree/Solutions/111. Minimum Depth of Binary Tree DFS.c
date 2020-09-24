/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int *a,int *b) {
    if((*a)<(*b)) return *a;
    else return *b;
}
void dfs(struct TreeNode* root,int *res) {
    if(root->left && root->right) {
        (*res)++;
        int x = (*res);
        dfs(root->right,res);
        dfs(root->left,&x);
        (*res) = min(&x,res);
    }
    else if(root->left) (*res)++,dfs(root->left,res);
    else if(root->right) (*res)++,dfs(root->right,res);
}

int minDepth(struct TreeNode* root){
    if(!root) return 0;
    int res=1;
    dfs(root,&res);
    return res;
}