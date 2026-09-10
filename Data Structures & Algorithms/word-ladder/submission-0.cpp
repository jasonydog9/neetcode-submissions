class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adj;

        for (int i = 0; i < wordList.size(); i++)
        {
            int count = 0;
            int diff = 0;
            for (char c : beginWord)
            {
                if (c != wordList[i][count])
                    diff++;
                count++;
            }
            if (diff != 1)
                continue;

            adj[beginWord].push_back(wordList[i]);
            adj[wordList[i]].push_back(beginWord);
        }
        for (int i = 0;i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                int diff = 0;
                int count = 0;
                for (char c : wordList[i])
                {
                    if (c != wordList[j][count])
                        diff++;
                    count++;
                }
                if (diff != 1)
                    continue;

                adj[wordList[i]].push_back(wordList[j]);
                adj[wordList[j]].push_back(wordList[i]);
                
            }
        }

        set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty())
        {
            int level_size = q.size();

            for (int i  =0 ; i < level_size; i++)
            {
                string ele = q.front();
                q.pop();

                if (ele == endWord)
                    return level;
                if (visited.contains(ele))
                    continue;
                visited.insert(ele);
                for (string s : adj[ele])
                {
                    q.push(s);
                }

            }
            level++;
        }
        return 0;
    }
};
