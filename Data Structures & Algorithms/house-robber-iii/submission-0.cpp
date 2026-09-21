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
    int rob(TreeNode* root) {
        return max(dfs(root).first, dfs(root).second);
    }

    pair<int,int> dfs(TreeNode* root)
    {
        if (root == nullptr)
            return make_pair(0,0);

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int robbed = root->val + left.second + right.second;
        int notRobbed = max(left.first, left.second) + max(right.first, right.second);

        return make_pair(robbed, notRobbed);
    }
};