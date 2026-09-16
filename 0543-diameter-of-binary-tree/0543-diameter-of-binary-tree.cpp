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
    int diameter = 0;
    int maxdepth(TreeNode* root) {
        if (!root) return 0;
        int leftht = maxdepth(root->left);
        int rightht = maxdepth(root->right);

        diameter = max(diameter, leftht + rightht);

        return 1 + max(leftht, rightht);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return diameter;
    }
};