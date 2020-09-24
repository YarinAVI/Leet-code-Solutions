/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right = NULL;
    root->left = NULL;
    struct TreeNode *insertor;
    int i;
    root->val = preorder[0];
    for(i=1;i<preorderSize;i++) {
        int val = preorder[i];
        insertor = root;
    while(insertor) {
        if(val<insertor->val && insertor->left) insertor = insertor->left;
        else if(val<insertor->val && !insertor->left) {
            insertor->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            insertor->left->left = NULL;
            insertor->left->right = NULL;
            insertor->left->val = val;
            break;
        }
        else if(val>insertor->val && insertor->right) insertor = insertor->right;
        else if(val>insertor->val && !insertor->right)  {
            insertor->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            insertor->right->left = NULL;
            insertor->right->right = NULL;
            insertor->right->val = val;
            break;
        }
    }
    }
    return root;
    
}