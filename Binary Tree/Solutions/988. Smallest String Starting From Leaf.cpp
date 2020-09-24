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
    void dfs(TreeNode* root,string temp,string &res) {
        temp+=root->val+'a';
        if(root->left) dfs(root->left,temp,res);
        if(root->right)dfs(root->right,temp,res);
        if(!root->left && !root->right) {
            std::reverse(temp.begin(),temp.end());
            if(temp<res) res=temp;
        }
    }
    string smallestFromLeaf(TreeNode* root) {
       string res (8500,'z');
        string temp;
        if(!root) return temp;
        dfs(root,temp,res);
        return res;
    }
};