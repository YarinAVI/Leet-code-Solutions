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
    vector<int> findMode(TreeNode* root) {
        vector<int > res;
        if(!root) return res;
        unordered_map<int,int> m;
        unordered_set<int> s;
        dfs(root,m);
        int max = INT_MIN;
        for(auto j = m.begin();j!=m.end();j++) if(j->second>max) max = j->second;
        for(auto j =m.begin();j!=m.end();j++) if(j->second == max) s.insert(j->first);
        for(auto j =s.begin();j!=s.end();j++) res.push_back(*j);
        return res;
    }
private:
    void dfs(TreeNode* root, unordered_map<int,int> &m)  {
        if(m.find(root->val) !=m.end()) m.at(root->val)++;
        else m.insert({root->val,0});
        if(root->left) dfs(root->left,m);
        if(root->right) dfs(root->right,m);
    }
};