
class Solution {
public:
    void myPostorderTraversal(TreeNode* root, vector<int> &vec) {
        if (!root) return;
        myPostorderTraversal(root->left, vec);
        myPostorderTraversal(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        myPostorderTraversal(root, result);
        return result;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sk;

        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while (!sk.empty() || curr != NULL) {
            while (curr != NULL) {
                sk.push(curr);
                curr = curr->left;
            }
            curr = sk.top();
            if (curr->right == NULL || curr->right == prev) {
                result.push_back(curr->val);
                sk.pop();
                prev = curr;
                curr = NULL;
            } else {
                curr = curr->right;
            }
        }
        return result;
    }
};