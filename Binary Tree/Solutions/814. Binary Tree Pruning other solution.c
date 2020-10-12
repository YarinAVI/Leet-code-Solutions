/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode * root,int rm_val) {
        if(root->left)  {
            if(dfs(root->left,rm_val)) {
                free(root->left);
                root->left = NULL;
            }
        }
    if(root->right) {
        if(dfs(root->right,rm_val)) {
            free(root->right);
            root->right = NULL;
        }
    }
        if(!root->right && !root->left && root->val == rm_val) return true;
        return false;
    }
struct TreeNode* pruneTree(struct TreeNode* root){
    if(!root) return NULL; 
    if(dfs(root,0)) root = NULL;
    return root;
}