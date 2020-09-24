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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int res;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int k =0;
            vector<int> level;
            while(size) {
                if(q.front()) {
                    q.push(q.front()->left),q.push(q.front()->right);
                    level.push_back(q.front()->val);
                }
                else level.push_back(0), k++;
                size--;
                q.pop();
            }
            
            if(k==level.size()) goto A;
            res = 0;
            for(int i =0;i<level.size();i++) res+=level[i]; 
        }
        A:
        return res;
    }
};