/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countNodes(struct TreeNode* root){
    int res=0;
    if(!root) return 0;
    res++;
    if(root->right) res+=countNodes(root->right);
    if(root->left) res+=countNodes(root->left);
    return res;
}