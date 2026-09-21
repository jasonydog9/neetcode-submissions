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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* prev = root;
        TreeNode* curr = root;
        while (curr != nullptr)
        {
            if (val > curr->val)
            {
                prev = curr;
                curr = curr->right;
            }
            else if (val < curr->val)
            {
                prev = curr;
                curr = curr->left;
            }
        }
        if (prev != nullptr && val < prev->val)
        {
            prev->left = new TreeNode(val);
        }
        else if (prev != nullptr && val > prev->val)
            prev->right = new TreeNode(val);
        else if (prev == nullptr)
            root = new TreeNode(val);

        return root;
    }
};