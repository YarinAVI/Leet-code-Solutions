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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        pre(root,res);
        return res;
    }
private:
    void pre(Node* curr_node,vector<int> &res) {
        res.push_back(curr_node->val);
        int i;
        for(i=0;i<curr_node->children.size();i++) pre(curr_node->children[i],res);
    }
};