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
    void post(TreeNode* root, vector<int> &res) {
        if(!root) return;
        
        if(root->right && root->left) {
            post(root->left,res);
            post(root->right,res);
            res.push_back(root->val);
        }
        else if(root->left) {
             post(root->left,res);
            res.push_back(root->val);
        }
        else if(root->right) {
            post(root->right,res);
            res.push_back(root->val);
        }
        else res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> res;
        post(root,res);
        return res;
    }
};