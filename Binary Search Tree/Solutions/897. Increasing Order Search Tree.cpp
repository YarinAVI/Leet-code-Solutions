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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*> q;
        inorder(root,q);
        TreeNode* res = q.front();
        TreeNode* temp = nullptr;
        while(!q.empty()) {
            temp = q.front();
            temp->left = nullptr;
            q.pop();
           if(!q.empty()) temp->right = q.front();
        }
        return res;
    }
private:
    void inorder(TreeNode* root,queue<TreeNode*>&q) {
        if(root->left) inorder(root->left,q);
        q.push(root);
        if(root->right)inorder(root->right,q);
    }
};