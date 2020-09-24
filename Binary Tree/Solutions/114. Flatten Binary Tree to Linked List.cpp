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
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> q;
        dfs(root,q);
        int i;
        for(i=0;i<q.size()-1;i++) {
            q[i]->right = q[i+1];
            q[i]->left = nullptr;
        }
        q[i]->right=nullptr;
        q[i]->left=nullptr;
    }
private:
    void dfs(TreeNode* root,vector<TreeNode*> &q) {
        q.push_back(root);
        if(root->left)dfs(root->left,q);
        if(root->right)dfs(root->right,q);
    }
};