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
    vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            int size_row = q.size();
            int temp = size_row;
            double avg_this_row=0;
            while(size_row) {
                if(q.front()->right) q.push(q.front()->right);
                if(q.front()->left) q.push(q.front()->left);
                avg_this_row+=q.front()->val;
                q.pop();
                size_row--;
            }
           avg_this_row = avg_this_row/temp;
            res.push_back(avg_this_row);
        }
        return res;
    }
};