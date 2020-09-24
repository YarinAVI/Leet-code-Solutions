/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<TreeNode*> target_nodes;
        find(s,t->val,target_nodes);
        int i;
        for(i=0;i<target_nodes.size();i++) {
            if(cmp_tree(t,target_nodes[i])) return true;
        }
        return false;
    }
private:
    void find(TreeNode* root,int target,vector<TreeNode*> &target_nodes) {
        if(root->val == target) target_nodes.push_back(root);
        if(root->left) find(root->left,target,target_nodes);
        if(root->right) find(root->right,target,target_nodes);
    }
    bool cmp_tree(TreeNode *s,TreeNode *t) {
        
        if(!s && !t) return true;
        else if(!s && t) return false;
        else if(s && !t) return false;
        else if(s->val !=t->val) return false;
        return cmp_tree(s->left,t->left) && cmp_tree(s->right,t->right);
    }
};