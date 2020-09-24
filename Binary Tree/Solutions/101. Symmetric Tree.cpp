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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else if (root->right && !root->left || root->left && !root->right) return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int temp_size = q.size();
            vector<int> palindrome_vector;
            while (temp_size) {
                if (q.front()) {
                    q.push(q.front()->left), q.push(q.front()->right);
                    palindrome_vector.push_back(q.front()->val);
                }
                else palindrome_vector.push_back(0);
                temp_size--;
                q.pop();
            }
            if (!is_palindrome(palindrome_vector)) return false;
        }
        return true;
    }
    bool is_palindrome(vector<int>& q) {
        int i = 0, j = q.size() - 1;
        for (; i < j; i++, j--) if (q[i] != q[j]) return false;

        return true;
    }
};