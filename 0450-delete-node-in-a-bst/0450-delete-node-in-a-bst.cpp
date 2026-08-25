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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) return NULL;

        //search left
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        //search right
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        //reached that node
        //check for Four conditions.

        //1. No childrens of that node
        else{
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL; //NULL gets connected to the node above root
        }

        //2. Child is present at left side 
        if(root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        //3. Child is present at right side 
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        //4. Child is at both sides
        //greatest node from the left side of root(key)

        //first come to left side of that root
        TreeNode* temp = root->left;

        while(temp->right != NULL) {
            temp = temp->right;
        }

        //assign the root with greatest
        root->val = temp->val;

        //remove the duplicate which is at down.
        root->left = deleteNode(root->left, temp->val); //we passed temp->val (the greatest left node)

        }

        return root;
    }
};