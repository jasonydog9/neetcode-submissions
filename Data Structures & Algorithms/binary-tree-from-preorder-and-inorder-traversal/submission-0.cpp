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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        root->val = preorder[0];
        int mid = 0;
        for (int idx = 0; idx < (int)inorder.size(); idx++)
        {
            if (inorder[idx] == preorder[0])
            {
                mid = idx;
                break;
            }
        }
        vector<int> new_inorder(inorder.begin(), inorder.begin() + mid);
        vector<int> new_preorder(preorder.begin() + 1, preorder.begin() + mid + 1);
        root->left = buildTree(new_preorder, new_inorder);
        vector<int> n_inorder(inorder.begin() + mid + 1, inorder.end());
        vector<int> n_preorder(preorder.begin() + mid + 1, preorder.end());
        root->right = buildTree(n_preorder, n_inorder);
        return root;
    }
};
