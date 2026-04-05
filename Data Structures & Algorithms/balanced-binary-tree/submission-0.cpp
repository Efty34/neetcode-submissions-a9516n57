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
    int ans = 0;

private:
    int dfs_height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = dfs_height(root->left);
        int right = dfs_height(root->right);

        ans = max(ans, abs(left - right));

        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        ans = 0;
        dfs_height(root);
        return ans <= 1;
    }
};
