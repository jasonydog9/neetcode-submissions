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
    int goodNodes(TreeNode* root) {
        return dfs(root, -100);
    }

    int dfs(TreeNode* root, int max)
    {
        if (root == nullptr)
            return 0;

        int total = 0;
        if (root->val >= max)
        {
            total++;
            max = root->val;
        }
        total += dfs(root->left, max) + dfs(root->right, max);

        return total;
    }
};
