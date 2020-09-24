/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *t1,struct TreeNode*t2) {
    t1->val+=t2->val;
    if(t1->left && t1->right) {
        
    if(t2->right && t2->left) dfs(t1->right,t2->right),dfs(t1->left,t2->left);
    else if(t2->right) dfs(t1->right,t2->right);
    else if(t2->left) dfs(t1->left,t2->left);
    }
    
    else if(t1->right) {
            if(t2->right && t2->left) dfs(t1->right,t2->right) , t1->left =t2->left;
    else if(t2->right) dfs(t1->right,t2->right);
    else if(t2->left) t1->left = t2->left;
    }
    
    else if(t1->left) {
                    if(t2->right && t2->left) dfs(t1->left,t2->left) , t1->right =t2->right;
    else if(t2->right) t1->right = t2->right;
    else if(t2->left) dfs(t1->left,t2->left);
    }
    else {
        if(t2->left) t1->left = t2->left;
        if(t2->right) t1->right = t2->right;
    }
    
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(t1==NULL) return t2;
    else if(t2==NULL) return t1;
    dfs(t1,t2);
    return t1;
}