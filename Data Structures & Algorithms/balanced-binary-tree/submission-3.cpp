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
    bool isBalanced(TreeNode* root) {
        vector<bool> res;
        res.resize(1);
        res[0] = true;
        dfs(root, res);
        return res[0];
    }

    int dfs(TreeNode* root,vector<bool>& res)
    {
        if (root == nullptr)
            return 0;
        
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        if (abs(left - right) > 1)
            res[0] = false;

        return max(left, right) + 1;
    }

};
