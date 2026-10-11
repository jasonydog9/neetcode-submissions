class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }

        string res;
        for (char c : order)
        {
            if (mp.contains(c))
            {
                for (int i = 0; i < mp[c]; i++)
                    res += c;
                mp.erase(c);
            }
        }
        for (const auto& [k, v] : mp)
        {
            for (int i = 0; i < v; i++)
                res += k;
        }
        return res;
    }
};