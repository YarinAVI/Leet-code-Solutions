/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool find_from(struct TreeNode *s,struct TreeNode *t) {
    if(!s && !t) return true;
    else if(!s && t) return false;
    else if(s && !t) return false;
    else if(s->val != t->val) return false;
    return find_from(s->left,t->left) && find_from(s->right,t->right);
}
void post_order_find(struct TreeNode *s,struct TreeNode *t,bool *res) {
    if(s->val == t->val) (*res) |=find_from(s,t);
    if(*res) return;
    if(s->left) post_order_find(s->left,t,res);
    if(s->right)post_order_find(s->right,t,res);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    bool res = false;
    post_order_find(s,t,&res);
    return res;
}