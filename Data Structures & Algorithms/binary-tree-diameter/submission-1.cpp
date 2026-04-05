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


class Solution
{
    int max_diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs_height(root);
        return max_diameter;
    }

private:
    int dfs_height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = dfs_height(root->left);
        int right = dfs_height(root->right);

        max_diameter = max(max_diameter, left + right);

        return max(left, right) + 1;
    }
};
