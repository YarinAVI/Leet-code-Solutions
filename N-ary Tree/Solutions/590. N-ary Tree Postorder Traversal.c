/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void post(struct Node* root,int **res,int *returnSize){
    int i;
    for(i=0;i<root->numChildren;i++) {
        post(root->children[i],res,returnSize);
    }
    (*res) = (int*)realloc(*res,(*returnSize)*sizeof(int));
    (*res)[(*returnSize)-1] = root->val;
    (*returnSize)++;
}
int* postorder(struct Node* root, int* returnSize) {
    
    (*returnSize)=1;
    int *res = (int*)malloc(sizeof(int));
    if(!root) {
        (*returnSize) = 0;
        return res;
    }
    post(root,&res,returnSize);
    (*returnSize)--;
    return res;
}