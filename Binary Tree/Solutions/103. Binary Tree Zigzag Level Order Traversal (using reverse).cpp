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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int toggle = 1;
        if(!root) return res;
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while(size) {
                if(q.front()->right) q.push(q.front()->right);
                if(q.front()->left) q.push(q.front()->left);
                temp.push_back(q.front()->val);
                size--;
                q.pop();
            }
            if(toggle) reverse(temp.begin(),temp.end());
            res.push_back(temp);
            toggle = !toggle;
        }
        return res;
    }
};