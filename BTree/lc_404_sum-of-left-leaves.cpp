

class Solution {
private:
    int result;
public:
    void mySumOfLeftLeaves(TreeNode* root, TreeNode* pp) {
        if (!root) return;

        if (!root->left && !root->right && pp && root == pp->left) {
            result += root->val;
            return;
        }

        mySumOfLeftLeaves(root->left, root);
        mySumOfLeftLeaves(root->right, root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        result = 0;
        mySumOfLeftLeaves(root, NULL);
        return result;
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        
        int sum = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + sum;
    }
};