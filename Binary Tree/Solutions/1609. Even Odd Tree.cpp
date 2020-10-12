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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool odd = false;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            while(size) {
                if(q.front()->left)  q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
    
                level.push_back(q.front()->val);
                size--;
                 q.pop();
            }
            if(odd) {
                if(level.size()==1) {
                    if(level[0]%2!=0) return false;
                }
                for(int i=0;i<level.size()-1;i++) {
                    if(level[i]%2!=0) return false;
                    if(level[i+1]%2!=0) return false;
                    if(level[i] <= level[i+1]) return false;
                }
            }
            else {
                if(level.size()==1) {
                    if(level[0]%2==0) return false;
                }
                for(int i=0;i<level.size()-1;i++) {
                    if(level[i]%2==0) return false;
                    if(level[i+1]%2==0) return false;
                    if(level[i] >= level[i+1]) return false;
                }
            }
            odd = !odd;
            
        }
        return true;
    }
};