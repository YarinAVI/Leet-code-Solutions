/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find_t_root(struct TreeNode* root,struct TreeNode*** target_node_list,int target,u_int *ls) {
    if(root->val == target) {
        (*target_node_list) = (struct TreeNode**)realloc((*target_node_list),++(*ls)*sizeof(struct TreeNode*));
        (*target_node_list)[(*ls)-1] = root;
    }
    if(root->left) find_t_root(root->left,target_node_list,target,ls);
    if(root->right)find_t_root(root->right,target_node_list,target,ls);
}
bool cmp_tree(struct TreeNode *s, struct TreeNode *t) {
        if(!s && !t) return true;
        else if(!s && t) return false;
        else if(s && !t) return false;
        else if(s->val !=t->val) return false;
        return cmp_tree(s->left,t->left) && cmp_tree(s->right,t->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    struct TreeNode **target_node_list = NULL;
    u_int list_size = 0;
    find_t_root(s,&target_node_list,t->val,&list_size);
    int i;
    // for each found T root node in S, compare the tree from that node.
    for(i=0;i<list_size;i++) {
        if(cmp_tree(t,target_node_list[i])) return true;
    }
    return false;
}