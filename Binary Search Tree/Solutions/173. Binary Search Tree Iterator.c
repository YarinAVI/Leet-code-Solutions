/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct {
    int curr;
    int size;
    int *arr;
    
} BSTIterator;

void inorder(struct TreeNode* root,BSTIterator *obj) {
    if(!root) return;
    if(root->right && root->left) {
        inorder(root->left,obj);
        obj->size++;
        obj->arr = (int*)realloc(obj->arr,(obj->size-1)*sizeof(int) + sizeof(int));
        obj->arr[obj->size-1] = root->val;
        inorder(root->right,obj);
    }
    else if(root->right) {
        obj->size++;
        obj->arr = (int*)realloc(obj->arr,(obj->size-1)*sizeof(int) + sizeof(int));
        obj->arr[obj->size-1] = root->val;
        inorder(root->right,obj);
    }
    else if(root->left) {
        inorder(root->left,obj);
        obj->size++;
        obj->arr = (int*)realloc(obj->arr,(obj->size-1)*sizeof(int) + sizeof(int));
        obj->arr[obj->size-1] = root->val;
    }
    else {
        obj->size++;
        obj->arr = (int*)realloc(obj->arr,(obj->size-1)*sizeof(int) + sizeof(int));
        obj->arr[obj->size-1] = root->val;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = (BSTIterator*)calloc(1,sizeof(BSTIterator));
    inorder(root,obj);
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    obj->curr++;
    return obj->arr[obj->curr-1];
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->curr<obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/