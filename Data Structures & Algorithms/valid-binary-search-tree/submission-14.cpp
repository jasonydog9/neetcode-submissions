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
    vector<bool> res;
    bool isValidBST(TreeNode* root) {
        res.resize(1, true);
        dfs(root, -1000000000,1000000000);
        return res[0];

    }

    void dfs(TreeNode* root, int min, int max)
    {
        if (root == nullptr)
            return;

        if (root->val <= min || root->val >= max)  
            res[0] = false;

        dfs(root->left, min, std::min(max, root->val));
        dfs(root->right, std::max(min, root->val), max);
    }
};
