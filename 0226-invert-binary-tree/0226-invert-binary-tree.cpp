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
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        } else {
            // Invert left and right subtree
            invertTree(root->right);
            invertTree(root->left);
            // Swap the nodes
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            return root;
        }
    }
};