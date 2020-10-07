/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void cut_and_paste( struct TreeNode *root,struct TreeNode * addr) {
    while(root->left) {
        root = root->left;
    }
    root->left = addr;
}

bool dfs(struct TreeNode *root,int key) {
    if(root->val == key) {
        return true;
    }
    else if(root->val > key) {
        if(root->left) {
            if(dfs(root->left,key)) {
                struct TreeNode * rm = root->left;
                if(root->left->left && root->left->right) {
                    root->left = root->left->right;
                    struct TreeNode *rmr = rm->left;
                    free(rm);
                    cut_and_paste(root->left,rmr);
                }
                else if(root->left->left) {
                    root->left = root->left->left;
                    free(rm);
                } 
                else if(root->left->right) {
                    root->left = root->left->right;
                    free(rm);
                }
                else {
                    free(rm);
                    root->left = NULL;
                }
            }
        } 
    }
    else if(root->val < key) {
        if(root->right) {
            if(dfs(root->right,key)) {
                struct TreeNode * rm = root->right;
                if(root->right->left && root->right->right) {
                    root->right = root->right->right;
                    struct TreeNode *rmr = rm->left;
                    free(rm);
                    cut_and_paste(root->right,rmr);
                }
                else if(root->right->left) {
                    root->right = root->right->left;
                    free(rm);
                }
                else if(root->right->right) {
                    root->right = root->right->right;
                    free(rm);
                }
                else {
                    free(rm);
                    root->right = NULL;
                }
            }
        }
    }
    return false;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(!root) return NULL;
    if (dfs(root,key)) {
        struct TreeNode * rm = root;
        if(root->left && root->right) {
            root = root->right;
            cut_and_paste(root,rm->left);
            free(rm);
        }
        else if(root->left) {
            root = root->left;
            free(rm);
        }
        else if(root->right) {
            root = root->right;
            free(rm);
        }
        else {
            free(rm);
            root = NULL;
        }
    }
    return root;
}
