/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // use pre-order to serialize
    void pre_order(TreeNode * root,string &ser) {
        ser+= to_string(root->val),ser+=',';

        if(root->left) pre_order(root->left,ser);
        if(root->right)pre_order(root->right,ser);
    }
    string serialize(TreeNode* root) {
                
        string ser;
      if(!root) return ser;
        pre_order(root,ser);
        ser.pop_back();
      //  cout << ser;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t ptr = 0;
        if(data.empty()) return NULL;
        while(ptr < data.size() && data[ptr]!=',') ptr++;
        ptr++;
        TreeNode * root = (TreeNode*)calloc(1,sizeof(TreeNode));
        root->val = std::stoi(data);
        
        while(ptr<data.size()) {
           TreeNode * inserter = root; 
           int val = std::stoi(data.substr(ptr,data.size()));
            while(inserter) {
            if(val > inserter->val && inserter->right) inserter = inserter->right;
            else if(val> inserter->val && !inserter->right) {
                inserter->right = (TreeNode*)calloc(1,sizeof(TreeNode));
                inserter->right->val = val;
                break;
            }
            else if(val < inserter->val && inserter->left) inserter = inserter->left;
            else if(val < inserter->val && !inserter->left) {
                inserter->left = (TreeNode*)calloc(1,sizeof(TreeNode));
                inserter->left->val = val;
                break;
            }
            }
            
        while(ptr < data.size() && data[ptr]!=',') ptr++;
        ptr++;
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;