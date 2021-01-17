

class Solution {
public:
    void myBinaryTreePaths(TreeNode* root, vector<string> &result, string str) {
        if (!root) return;
        if (str.empty()) {
            str.append(to_string(root->val));
        } else {
            str.append("->").append(to_string(root->val));
        }
        if (!root->left && !root->right) {
            result.push_back(str);
            return;
        }
        myBinaryTreePaths(root->left, result, str);
        myBinaryTreePaths(root->right, result, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        myBinaryTreePaths(root, result, "");
        return result;
    }
};