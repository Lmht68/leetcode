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
    int diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs_height(root);
        return diameter;
    }

private:
    int dfs_height(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left_h = dfs_height(node->left);
        int right_h = dfs_height(node->right);

        diameter = std::max(diameter, left_h + right_h);
        return 1 + std::max(left_h, right_h);
    }
};