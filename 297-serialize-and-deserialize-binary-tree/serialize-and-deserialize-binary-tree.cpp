/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // ------------------- SERIALIZATION -------------------

    // Performs preorder traversal and converts the tree
    // into a comma-separated string.
    void preorder(TreeNode* root, string &ans) {

        // Use '#' to represent NULL nodes.
        if (root == nullptr) {
            ans += "#,";
            return;
        }

        // Store current node value.
        ans += to_string(root->val) + ",";

        // Serialize left subtree.
        preorder(root->left, ans);

        // Serialize right subtree.
        preorder(root->right, ans);
    }

    string serialize(TreeNode* root) {

        string ans;

        preorder(root, ans);

        return ans;
    }


    // ------------------- DESERIALIZATION -------------------

    TreeNode* buildTree(string &data, int &index) {

        // If current token is '#', this is a NULL node.
        if (data[index] == '#') {

            // Skip "#,"
            index += 2;

            return nullptr;
        }

        // Read current integer.
        int sign = 1;

        if (data[index] == '-') {
            sign = -1;
            index++;
        }

        int num = 0;

        while (index < data.size() && data[index] != ',') {
            num = num * 10 + (data[index] - '0');
            index++;
        }

        num *= sign;

        // Skip comma.
        index++;

        // Create node.
        TreeNode* root = new TreeNode(num);

        // Build left subtree.
        root->left = buildTree(data, index);

        // Build right subtree.
        root->right = buildTree(data, index);

        return root;
    }

    TreeNode* deserialize(string data) {

        int index = 0;

        return buildTree(data, index);
    }
};