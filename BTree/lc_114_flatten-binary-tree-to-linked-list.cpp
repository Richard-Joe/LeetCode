

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class Solution {
public:

    TreeNode* myFlatten(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* l = myFlatten(root->left);
        TreeNode* r = myFlatten(root->right);

        TreeNode* last = l;
        while(last && last->right) {
            last = last->right;
        }

        root->left = NULL;
        if (l) {
            last->right = r;
            root->right = l;
        } else {
            root->right = r;
        }

        return root;
    }

    void flatten(TreeNode* root) {
        myFlatten(root);
    }
};