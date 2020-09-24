/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/discuss/836083/Neat-solution-using-realloc-very-good-for-C-programmers-out-here
void dfs(struct TreeNode* root, int size,bool ** arr,int *res) {
    (*arr) = (bool*)realloc((*arr),size*sizeof(bool));
    (*arr)[size-1] = (bool)root->val;
    
    
    if(root->left) dfs(root->left,size+1,arr,res);
    if(root->right) dfs(root->right,size+1,arr,res);
    
    if(!root->left && !root->right) {
        
    for(int i=0;i<size;i++) (*res)+= (*arr)[i] * pow(2,size-i-1);
        
    }
}
int sumRootToLeaf(struct TreeNode* root){
    int res = 0;
    if(!root) return res;
    bool *arr = NULL;
    dfs(root,1,&arr,&res);
    return res;
}