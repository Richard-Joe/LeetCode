struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int>> result;
public:
    void myLevelOrder(TreeNode* root, int depth) {
        if (!root) return;
        if (result.size() < depth) {
            vector<int> tmp;
            tmp.push_back(root->val);
            result.push_back(tmp);
        } else {
            result[depth - 1].push_back(root->val);
        }
        myLevelOrder(root->left, depth + 1);
        myLevelOrder(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        myLevelOrder(root, 1);
        return result;
    }
};