/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;
            int size = q.size();
            while(size) {
                int i;
                for(i=0;i<q.front()->children.size();i++) q.push(q.front()->children[i]);
                temp.push_back(q.front()->val);
                q.pop();
                size--;
            }
            res.push_back(temp);
        }
        return res;
    }
};