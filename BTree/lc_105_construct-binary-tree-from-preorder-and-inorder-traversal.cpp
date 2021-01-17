#include <unordered_map.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right) return NULL;

        // 前序遍历中第一个是根结点
        int preorder_root = preorder[preorder_left];
        // 找到根结点在中序遍历中的位置
        int inorder_root = index[preorder_root];

        // 中序遍历中左子树的个数
        int left_num = inorder_root - inorder_left;
        // 中序遍历中右子树的个数
        // int right_num = inorder_right - inorder_root;

        TreeNode *root = new TreeNode(preorder_root);

        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + left_num, inorder_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + left_num + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

int main(void)
{
    return 0;
}