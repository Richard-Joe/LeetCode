
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void myInorderTraversal(struct TreeNode* root, int *result, int *index) {
    if (!root) return;
    myInorderTraversal(root->left, result, index);
    result[*index] = root->val;
    *index = *index + 1;
    myInorderTraversal(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * 100);
    int index = 0;
    myInorderTraversal(root, result, &index);

    *returnSize = index;
    return result;
}