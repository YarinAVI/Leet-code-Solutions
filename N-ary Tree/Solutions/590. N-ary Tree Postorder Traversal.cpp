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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        post(root,res);
        return res;
    }
private:
    void post(Node* curr_node,vector<int> &res) {
        int i;
        for(i=0;i<curr_node->children.size();i++) post(curr_node->children[i],res);
        res.push_back(curr_node->val);
    }
};