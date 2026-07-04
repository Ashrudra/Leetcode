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

    // Stores the index of every value in inorder traversal
    unordered_map<int, int> inorderIndex;

    // Points to the current root in preorder traversal
    int preorderIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int left, int right) {

        // No elements left in this subtree
        if (left > right)
            return nullptr;

        // Current preorder element is the root
        int rootValue = preorder[preorderIndex++];

        // Create the root node
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderIndex[rootValue];

        // Build left subtree
        root->left = build(preorder, inorder, left, mid - 1);

        // Build right subtree
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};