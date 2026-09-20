class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> answer;

        if (root == NULL)
            return answer;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);

                // Last node of this level
                if (i == size - 1)
                    answer.push_back(node->val);
            }
        }

        return answer;
    }
};