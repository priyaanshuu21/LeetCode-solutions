class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return{};

        vector<int>answer;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            TreeNode* node = que.front();

            while(n--) {
                node = que.front();
                que.pop();

                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
            answer.push_back(node->val);
        }
        return answer;
    }
};