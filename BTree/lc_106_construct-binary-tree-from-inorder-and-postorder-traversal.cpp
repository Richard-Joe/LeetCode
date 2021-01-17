
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
    TreeNode* myBuildTree(const vector<int>& inorder, const vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right)
    {
        if (postorder_left > postorder_right) return NULL;

        // 后续遍历中最后一个是根结点
        int postorder_root = postorder[postorder_right];
        // 找到根结点在中序遍历中的位置
        int inorder_root = index[postorder_root];

        // 中序遍历中左子树的个数
        // int left_num = inorder_root - inorder_left;
        // 中序遍历中右子树的个数
        int right_num = inorder_right - inorder_root;

        TreeNode *root = new TreeNode(postorder_root);

        root->right = myBuildTree(inorder, postorder, inorder_root + 1, inorder_right, postorder_right - right_num, postorder_right - 1);
        root->left = myBuildTree(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_right - right_num - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return myBuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};

int main(void)
{
    return 0;
}