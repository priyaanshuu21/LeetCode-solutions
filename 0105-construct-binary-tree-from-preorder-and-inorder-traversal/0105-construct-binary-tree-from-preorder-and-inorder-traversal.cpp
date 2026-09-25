class Solution {
public:

    int preIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int start, int end) 
    {
        // No elements left
        if (start > end) {
            return NULL;
        }

        // 1. Take current root from preorder
        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        // 2. Find root in inorder
        int i;
        for (i = start; i <= end; i++) {
            if (inorder[i] == rootValue) {
                break;
            }
        }

        // 3. Build left subtree
        root->left = buildTreeHelper(preorder, inorder, start, i - 1);

        // 4. Build right subtree
        root->right = buildTreeHelper(preorder, inorder, i + 1, end);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
};