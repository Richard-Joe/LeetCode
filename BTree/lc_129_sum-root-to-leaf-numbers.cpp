struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int result;
public:
    void mySumNumbers(TreeNode* root, int sum) {
        if (!root) return;
        sum = (sum * 10) + root->val;
        if (!root->left && !root->right) {
            result += sum;
            return;
        }
        mySumNumbers(root->left, sum);
        mySumNumbers(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        result = 0;
        mySumNumbers(root, 0);
        return result;
    }
};