/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void get_leafs_left_to_right(struct TreeNode* root, int** arr,int *arr_size) {
    if(root->left)get_leafs_left_to_right(root->left,arr,arr_size);
    if(root->right)get_leafs_left_to_right(root->right,arr,arr_size);
    if(!root->left && !root->right) {
        (*arr) = (int*)realloc((*arr),++(*arr_size)*sizeof(int));
        (*arr)[(*arr_size)-1] = root ->val;
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int *arr1 = NULL;
    int arr1_size = 0;
    int *arr2 = NULL;
    int arr2_size = 0;
    if(!root1 || !root2) return false;
    get_leafs_left_to_right(root1,&arr1,&arr1_size);
    get_leafs_left_to_right(root2,&arr2,&arr2_size);
    if(arr1_size != arr2_size) return false;
    int i;
    for(i=0;i<arr1_size;i++) {
        if(arr1[i]!=arr2[i]) return false;
    }
    return true;
}