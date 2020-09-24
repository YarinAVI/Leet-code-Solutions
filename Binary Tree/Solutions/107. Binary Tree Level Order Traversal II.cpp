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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while(size) {
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            temp.push_back(q.front()->val);
            q.pop();
            size--;
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};