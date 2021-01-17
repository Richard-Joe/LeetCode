
class Solution {
public:
    void myPreorderTraversal(TreeNode* root, vector<int> &vec) {
        if (!root) return;
        vec.push_back(root->val);
        myPreorderTraversal(root->left, vec);
        myPreorderTraversal(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        myPreorderTraversal(root, result);
        return result;
    }
};