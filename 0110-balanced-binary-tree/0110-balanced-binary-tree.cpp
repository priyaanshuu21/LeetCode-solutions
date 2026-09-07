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
    int height(TreeNode* root) {
        //base case
        if(root == NULL) return 0;

        //left subtree height
        int leftht = height(root->left);
        if(leftht == -1) return -1;

        //right subtree height
        int rightht = height(root->right);
        if(rightht == -1) return -1;

        
        if(abs(leftht - rightht) > 1) return -1;

        return 1 + max(leftht, rightht);

    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;   //is height function actually giving a height? (balanced tree) or a -1.
    }
};