/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root,int **inorder_arr,int *size) {
    if(root) {
        inorder(root->left,inorder_arr,size);
                (*inorder_arr)[(*size)-1] = root->val;
                (*size)++;
        *inorder_arr = (int*)realloc(*inorder_arr,(*size)*sizeof(int));
        inorder(root->right,inorder_arr,size);
        free(root);
    }
}

bool findTarget(struct TreeNode* root, int k){
    if(!root) return false;
    int size =1;

    int *inorder_arr = (int*)malloc(sizeof(int));
    inorder(root,&inorder_arr,&size);
    int i=0,j=size-2;
    while(i<j) {
        if(inorder_arr[i]+inorder_arr[j]==k) {
           free(inorder_arr);
           return true; 
        } 
        else if(inorder_arr[i]+inorder_arr[j]>k) j--;
        else if(inorder_arr[j]+inorder_arr[i]<k) i++;
    }
    free(inorder_arr);
    return false;
}