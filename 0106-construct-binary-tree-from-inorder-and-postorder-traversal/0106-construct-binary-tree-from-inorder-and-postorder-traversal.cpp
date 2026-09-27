class Solution {
public:

    int postIndex;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int left, int right) {

        // No elements left
        if (left > right) {
            return NULL;
        }

        // Last/current element of postorder is the root
        int rootVal = postorder[postIndex];
        postIndex--;

        // Create root node
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int i = left;

        for (int a = left; a <= right; a++) {
            if (inorder[a] == rootVal) {
                i = a;
                break;
            }
        }

        // Build RIGHT subtree first
        root->right = helper(inorder, postorder, i + 1, right);

        // Then build LEFT subtree
        root->left = helper(inorder, postorder, left, i - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Start from the last element of postorder
        postIndex = postorder.size() - 1;

        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};