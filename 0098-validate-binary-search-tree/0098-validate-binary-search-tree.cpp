class Solution {

private:
    bool helper(TreeNode* root, long long min, long long max) {

        if (root == NULL)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return helper(root->left, min, root->val) &&
               helper(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};