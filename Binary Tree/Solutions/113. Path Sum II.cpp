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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp_arr;
        if(!root) return result;
        dfs(root,sum,result,temp_arr);
        return result;
    }
private:
    void dfs(TreeNode *root,int sum,vector<vector<int>> &result,vector<int> &temp_arr) {
        temp_arr.push_back(root->val);
        if(root->left) {
            dfs(root->left,sum-root->val,result,temp_arr);
            temp_arr.pop_back();
        } 
        if(root->right) {
            dfs(root->right,sum-root->val,result,temp_arr);
            temp_arr.pop_back();
        }
        if(!root->right&& !root->left && sum-root->val ==0) {
            result.push_back(temp_arr);
        }
    }
};