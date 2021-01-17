

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* prev = NULL;
struct TreeNode* a = NULL;
struct TreeNode* b = NULL;

void myRecoverTree(struct TreeNode* root){
    if (!root) return;
    myRecoverTree(root->left);
    if (prev->val > root->val) {
        a = (a == NULL ? prev : a);
        b = root;
    }
    prev = root;
    myRecoverTree(root->right);
}

void recoverTree(struct TreeNode* root){
    struct TreeNode pp;
    pp.val = INT_MIN;
    prev = &pp;
    a = b = NULL;
    myRecoverTree(root);
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}