
class Solution {
private:
    int result;
public:
    void mySumRootToLeaf(TreeNode* root, int sum) {
        if (!root) return;
        sum = sum * 2 + root->val;
        if (!root->left && !root->right) {
            result += sum;
            return;
        }
        mySumRootToLeaf(root->left, sum);
        mySumRootToLeaf(root->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        result = 0;
        mySumRootToLeaf(root, 0);
        return result;
    }
};