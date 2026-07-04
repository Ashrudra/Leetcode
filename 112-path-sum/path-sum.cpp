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
    bool hasPathSum(TreeNode* root, int targetSum) {

        // Base case:
        // If the tree is empty, there is no root-to-leaf path.
        if (root == nullptr)
            return false;

        // If the current node is a leaf node
        // (both left and right children are absent),
        // check whether its value equals the remaining target sum.
        if (root->left == nullptr && root->right == nullptr)
            return (targetSum == root->val);

        // Subtract the current node's value from the target.
        int remainingSum = targetSum - root->val;

        // Recursively check either the left subtree
        // or the right subtree.
        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    }
};