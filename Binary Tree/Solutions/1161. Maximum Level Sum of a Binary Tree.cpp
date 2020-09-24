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
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int max = INT_MIN;
        int res =1;
        int level = 1;
        while(!q.empty()) {
            int size = q.size();
            int temp = 0;
            while(size) {
                if(q.front()->right) q.push(q.front()->right);
                if(q.front()->left) q.push(q.front()->left);
                temp+=q.front()->val;
                q.pop();
                size--;
            }
            
            if(temp>max) res=level,max = temp;
            level++; 
        }
        return res;
    }
};