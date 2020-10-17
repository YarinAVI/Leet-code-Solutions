/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode * root,int *c,int k,int *res) {
    if(root->left) inorder(root->left,c,k,res);
    (*c)++;
    if( (*c)-1 == k) {
        (*res) = root->val;
        
        return;
    }
    
    if(root->right) inorder(root->right,c,k,res);
}

int kthSmallest(struct TreeNode* root, int k){
    int res;
    int c =1;
    inorder(root,&c,k,&res);
    return res;
}