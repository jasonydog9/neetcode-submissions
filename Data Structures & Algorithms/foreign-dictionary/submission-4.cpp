class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        set<char> bank;
        for (string& w : words)
            for (char c : w)
                bank.insert(c);
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (j >= words[i+1].size())
                    return "";
                if (words[i].at(j) != words[i + 1].at(j))
                {
                    if (!adj.contains(words[i].at(j)))
                        adj[words[i].at(j)] = vector<char>();
                    adj[words[i].at(j)].push_back(words[i + 1].at(j));
                    break;
                } 
            }
        }
        map<char, int> indegree;
        queue<char> q;
        string res;

        for (const auto& [key, value] : adj) {
            for (char c : value)
            {
                indegree[c]++;
            }
        }

        for (const auto& [key, value] : adj) {
            if (indegree[key] == 0)
                q.push(key);
        }

        while (!q.empty())
        {
            char top = q.front();
            q.pop();
            res += top;
            bank.erase(top);
            if (!adj.contains(top))
                continue;
            for (char c : adj[top])
            {
                indegree[c]--;
                if (indegree[c] == 0)
                    q.push(c);
            }
            
        }
        if (res.size() < adj.size())
            return "";
        for (char c : bank)
            res += c;
        return res;
    }
};
