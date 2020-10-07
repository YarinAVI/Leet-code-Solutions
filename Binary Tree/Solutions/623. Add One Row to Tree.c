/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// run 1 level before required level
void dfs(struct TreeNode* root,int level,int v,int d) {
    if(level == d) {
        if(root->left && root->right) {
            struct TreeNode * n1 = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            struct TreeNode * n2= (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            n1->val = v;
            n2->val = v;
            struct TreeNode * temp = root->left;
            root->left = n1;
            n1->left = temp;
            temp = root->right;
            root->right = n2;
            n2->right = temp;
        }
        else if(root->left) {
            struct TreeNode * n1 = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            struct TreeNode * n2= (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            n1->val = v;
            n2->val = v;
            struct TreeNode * temp = root->left;
            root->left = n1;
            n1->left = temp;
            root->right = n2;
        }
        else if(root->right) {
            struct TreeNode * n1 = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            struct TreeNode * n2= (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            n1->val = v;
            n2->val = v;
            struct TreeNode * temp = root->right;
            root->right = n1;
            n1->right = temp;
            root->left = n2;
        }
        else {
            struct TreeNode * n1 = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            struct TreeNode * n2= (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
            n1->val = v;
            n2->val = v;
            root->left = n1;
            root->right = n2;
        }
        return;
    }
if(root->left) dfs(root->left,level+1,v,d);
if(root->right) dfs(root->right,level+1,v,d);
}
struct TreeNode* addOneRow(struct TreeNode* root, int v, int d){
    if(d==1) {
        struct TreeNode * new_node = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
        new_node->val = v;
        new_node->left = root;
        return new_node;
    }
    dfs(root,2,v,d);
    return root;
}