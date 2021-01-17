
class Solution {
public:
    TreeNode* mySortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = mySortedArrayToBST(nums, l, m - 1);
        root->right = mySortedArrayToBST(nums, m + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return mySortedArrayToBST(nums, 0, nums.size() - 1);
    }
};