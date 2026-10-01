struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class WordDictionary {
public:

    TrieNode* start;
    WordDictionary() {
        start = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* curr = start;
        for (char c : word)
        {
            if (curr->children[c-'a'] == nullptr)
            {
                TrieNode* temp = new TrieNode();
                curr->children[c-'a'] = temp;
                curr = temp;
            }
            else
            {
                curr = curr->children[c-'a'];
            }
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        vector<bool> res;
        res.resize(1);
        dfs(word, 0, start, res);
        return res[0];
    }

    void dfs(string word, int idx, TrieNode* curr, vector<bool>& res)
    {
        if (idx >= word.size())
        {
            if (curr->isEnd)
                res[0] = true;
            return;
        }
        char c = word[idx];
        if (c == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] != nullptr)
                {
                    dfs(word, idx + 1, curr->children[i], res);
                }
            }
        }
        else
        {
            if (curr->children[word[idx] - 'a'])
                dfs(word, idx + 1, curr->children[word[idx] - 'a'], res);
        }
        return;
    }
};
