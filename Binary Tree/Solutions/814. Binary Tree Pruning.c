/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root) {
    bool is_one_left = 0;
    bool is_one_right = 0;
    if(root->left) {
        is_one_left = is_one_left || dfs(root->left);
        if(!is_one_left) root->left = NULL;
    }
    if(root->right) {
        is_one_right = is_one_right || dfs(root->right);
        if(!is_one_right) root->right = NULL;
    }
    if(!is_one_left && !is_one_right && root->val == 0)  {
        free(root);
        root=NULL;
    }
    else is_one_left = 1,is_one_right=1;
    
    return is_one_left || is_one_right;
}
struct TreeNode* pruneTree(struct TreeNode* root){
    if(!dfs(root)) root=NULL;
    return root;
}