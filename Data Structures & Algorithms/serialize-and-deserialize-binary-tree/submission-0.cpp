class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //level order traversal
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty())
        {
            int level_size = q.size();
            for (int i = 0; i < level_size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node == nullptr)
                {
                    res += "n";
                    res.push_back('e');
                    continue;
                }
                else
                {
                    res += to_string(node->val);
                    res.push_back('e');
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, 'e'))
            tokens.push_back(token);

        if (tokens.empty() || tokens[0] == "n")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < tokens.size())
        {
            TreeNode* node = q.front();
            q.pop();

            if (tokens[i] != "n")
            {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            if (i < tokens.size() && tokens[i] != "n")
            {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};