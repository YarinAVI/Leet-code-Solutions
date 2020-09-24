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
   void dfs(TreeNode* root,string &temp,vector<string>&res) {
        if(root->left && root->right) {
            string s = temp;
            temp+=to_string(root->val) +"->";
            dfs(root->left,temp,res);
            
            temp =s;
            temp+=to_string(root->val) +"->";
            dfs(root->right,temp,res);
        }
        else if(root->left && !root->right) {
            temp+=to_string(root->val) +"->";
            dfs(root->left,temp,res);
        }
        else if(root->right && !root->left) {
            temp+=to_string(root->val) +"->";
            dfs(root->right,temp,res);
        }
        else if(!root->right && !root->left) temp+=to_string(root->val),res.push_back(temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string temp;
        dfs(root,temp,res);
        return res;
    }
};