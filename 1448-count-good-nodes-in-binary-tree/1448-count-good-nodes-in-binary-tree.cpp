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
    private:
    void helper(TreeNode* root, int maxSoFar) {

        if(!root) return;

        if(root->val >= maxSoFar) count++;
        maxSoFar = max(maxSoFar, root->val);

        helper(root->left, maxSoFar);
        helper(root->right, maxSoFar);

    }
public:
    int maxSoFar = INT_MIN;
    int count = 0;

    int goodNodes(TreeNode* root) {
        helper(root, maxSoFar);
        return count;
    }
};