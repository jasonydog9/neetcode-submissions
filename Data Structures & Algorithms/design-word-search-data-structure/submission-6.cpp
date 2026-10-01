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
        return dfs(word, 0, start);
    }

    bool dfs(string word, int idx, TrieNode* curr)
    {
        for (int i = idx; i < word.size(); i++)
        {
            char c = word[i];
            if (c == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (curr->children[j] != nullptr && dfs(word, i + 1, curr->children[j]))
                        return true;

                }
                return false;
            }
            else
            {
                if (!curr->children[c - 'a'])
                    return false;
                curr = curr->children[c-'a'];
            }
        }
        return curr->isEnd;
    }
};
