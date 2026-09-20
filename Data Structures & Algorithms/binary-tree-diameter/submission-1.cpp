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
    vector<int> res;
    int diameterOfBinaryTree(TreeNode* root) {
        res.resize(1);
        res[0] = 0;
        dfs(root);
        return res[0];
    }

    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left);    
        int right = dfs(root->right);
        res[0] = max(left+right, res[0]);

        return max(left, right) + 1;
    }
};
