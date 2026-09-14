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
class BSTIterator {
public:
    stack<TreeNode*> stk;

    void leftMostNodes(TreeNode* root) {
        while(root!= NULL) {
            stk.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        leftMostNodes(root);  //stores all left most nodes in stack.
    }
    
    int next() {
        TreeNode* ans = stk.top();
        stk.pop();

        leftMostNodes(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return stk.size() > 0;  //if there is next element, the stack wont be empty.
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */