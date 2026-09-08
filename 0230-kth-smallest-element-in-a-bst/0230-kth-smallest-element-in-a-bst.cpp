/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int size(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + size(root->left) + size(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {

        if (root == NULL)
            return -1;

        int leftSize = size(root->left);

        // kth element is in left subtree
        if (k <= leftSize) {
            return kthSmallest(root->left, k);
        }

        // Current root is the kth smallest
        if (k == leftSize + 1) {
            return root->val;
        }

        // kth element is in right subtree
        return kthSmallest(root->right, k - leftSize - 1 );
    }
};