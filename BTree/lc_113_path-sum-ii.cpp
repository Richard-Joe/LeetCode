
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int>> result;
public:
    void myPathSum(TreeNode* root, vector<int> vec, int sum) {
        if (!root) return;
        vec.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) {
            result.push_back(vec);
            return;
        }
        myPathSum(root->left, vec, sum - root->val);
        myPathSum(root->right, vec, sum - root->val);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> vec;
        myPathSum(root, vec, sum);
        return result;
    }
};