/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode *aux;
    if(root) {
        if(root->right && root->left) {
        aux =root->right;
        root->right = root->left;
        root->left = aux;
        invertTree(root->left);
        invertTree(root->right);
        }
        else if(root->right && !root->left) {
            aux = root->right;
            root->right = NULL;
            root->left = aux;
            invertTree(root->left);
        }
        else if(root->left && !root->right) {
            aux = root->left;
            root->left = NULL;
            root->right =aux;
            invertTree(root->right);
        }
    }
    return root;
}