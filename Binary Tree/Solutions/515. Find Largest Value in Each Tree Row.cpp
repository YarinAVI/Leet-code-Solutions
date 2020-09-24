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
    vector<int> largestValues(TreeNode* root) { 
        std::ios::sync_with_stdio(false);
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int max =INT_MIN;
            while(size) {
                if(max<q.front()->val) max = q.front()->val;
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
                size--;
            }
            res.push_back(max);
        }
        return res;
    }
};