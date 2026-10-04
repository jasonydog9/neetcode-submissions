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
        return dfs(root, -101);
    }

    int dfs(TreeNode* root, int max)
    {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left, std::max(max, root->val));
        int right = dfs(root->right, std::max(max, root->val));

        int count = 0;
        if (root->val >= max)
            count++;

        return left + right + count;
    }
};
