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
    void inorder(TreeNode* root,vector<int>&res) {
        if(!root) return;
        if(root->left && root->right) {
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
            
        }
        else if(root->left) {
            inorder(root->left,res);
            res.push_back(root->val);
        } 
        else if(root->right) {
            res.push_back(root->val);
            inorder(root->right,res);
        } 
        else res.push_back(root->val);
    }
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> res;
        inorder(root,res);
        return res;
    }
};