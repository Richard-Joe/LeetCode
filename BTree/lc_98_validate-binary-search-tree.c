
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* prev = NULL;

bool myIsValidBST(struct TreeNode* root){
    if (!root) return true;
    if (!myIsValidBST(root->left)) return false;
    if (prev && prev->val >= root->val) return false;
    prev = root;
    if (!myIsValidBST(root->right)) return false;
    return true;
}

bool isValidBST(struct TreeNode* root){
    prev = NULL;
    return myIsValidBST(root);
}