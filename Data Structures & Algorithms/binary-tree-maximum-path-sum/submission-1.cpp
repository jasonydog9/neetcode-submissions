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
    int maxPathSum(TreeNode* root) {
        res.resize(1);
        res[0] = root->val;
        dfs(root);
        return res[0];
    }

    int dfs(TreeNode* root)
    {
        if (root == nullptr)    
            return 0;

        //go left
        int left = dfs(root->left);
        //go right
        int right = dfs(root->right);
        int leftTotal = root->val;
        int rightTotal = root->val;
        //update max if needed, check if adding left makes it smaller, if right makes it smaller, then add everything including the self node
        if (left + leftTotal > leftTotal)
            leftTotal += left;
        if (right + rightTotal > rightTotal)
            rightTotal += right;
        res[0] = std::max(res[0], leftTotal + rightTotal - root->val);
        return max(leftTotal, rightTotal);
        //return the max out of this node,
    }
};
