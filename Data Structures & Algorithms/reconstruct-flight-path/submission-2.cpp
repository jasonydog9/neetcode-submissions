class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> hashMap;
        for (vector<string> v : tickets)
        {
            if (!hashMap.contains(v[0]))
            {
                hashMap[v[0]] = vector<string>();
            }
            hashMap[v[0]].push_back(v[1]);
        }

        for (auto& [key, value] : hashMap)
        {
            sort(value.begin(), value.end(), greater<>());
        }

        vector<string> res;
        stack<string> s;
        s.push("JFK");
        while (!s.empty())
        {
            string top = s.top();
            if (hashMap.contains(top) && hashMap[top].size() > 0)
            {
                s.push(hashMap[top].back());
                hashMap[top].pop_back();
            }
            else
            {
                s.pop();
                res.push_back(top);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
