/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root,int *px,int sum) {
    
    if(root->left && root->right) {
        int x=(*px);
        (*px)+=root->right->val;
        x+=root->left->val;
        return dfs(root->right,px,sum) || dfs(root->left,&x,sum);
    }
    else if(root->left) {
        (*px)+=root->left->val;
        return dfs(root->left,px,sum);
        
    } 
    else if(root->right) {
        (*px)+=root->right->val;
        return dfs(root->right,px,sum);
    }
    if((*px)==sum) return true;
    else return false;
}

bool hasPathSum(struct TreeNode* root, int sum){
    if(!root) return false;
    int x=root->val;
    return dfs(root,&x,sum);
}