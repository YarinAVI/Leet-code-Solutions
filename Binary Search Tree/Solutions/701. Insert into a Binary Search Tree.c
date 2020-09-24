/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode * insertor = root;
    if(!insertor){
        insertor = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        insertor->val = val;
        insertor->left=NULL;
        insertor->right=NULL;
        root = insertor;
        return root;
    }
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
    return root;
}