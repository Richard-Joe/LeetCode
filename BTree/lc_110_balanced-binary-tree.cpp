
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool result;
public:
    int maxDepth(TreeNode* root) {
        if (!root || !result) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (abs(l - r) > 1) result = false;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        result = true;
        maxDepth(root);
        return result;
    }
};