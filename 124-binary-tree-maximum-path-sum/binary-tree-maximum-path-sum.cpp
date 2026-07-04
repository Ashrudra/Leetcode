class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculatePath(root, maxSum);
        return maxSum;
    }

private:
    int calculatePath(TreeNode* node, int& maxSum) {
        if (!node) {
            return 0;
        }

        int leftGain = max(calculatePath(node->left, maxSum), 0);
        int rightGain = max(calculatePath(node->right, maxSum), 0);

        int currentPathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }
};
