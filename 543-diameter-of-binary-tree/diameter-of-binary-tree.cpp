/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Stores the maximum diameter found so far.
    int diameter = 0;

    // Returns the height of the subtree rooted at 'root'.
    int height(TreeNode* root) {

        // Base case:
        // Height of an empty tree is 0.
        if (root == nullptr)
            return 0;

        // Compute height of left subtree.
        int leftHeight = height(root->left);

        // Compute height of right subtree.
        int rightHeight = height(root->right);

        // Diameter passing through the current node.
        // (Number of edges from deepest node in left subtree
        //  to deepest node in right subtree.)
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current node.
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        // Compute heights and update diameter.
        height(root);

        return diameter;
    }
};