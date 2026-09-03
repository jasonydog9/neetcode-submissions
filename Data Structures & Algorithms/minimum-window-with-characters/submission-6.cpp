class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash_s;
        unordered_map<char, int> hash_t;
        for (char c : t)
            hash_t[c]++;

        int l = 0;
        int r = 0;

        int res_l = 0;
        int res_len = INT_MAX;

        int required = hash_t.size();
        int formed = 0;
        while (r < s.size())
        {
            if (hash_t.contains(s[r]))
            {
                hash_s[s[r]]++;
                if (hash_s[s[r]] == hash_t[s[r]])
                    formed++;
            }
            while (formed == required)
            {
                int curr_len = r - l + 1;
                if (curr_len < res_len)
                {
                    res_len = curr_len;
                    res_l = l;
                }

                if (hash_t.contains(s[l]))
                {
                    hash_s[s[l]]--;
                    if (hash_s[s[l]] < hash_t[s[l]])
                        formed--;
                }
                l++;
            }
            r++;
        }

        if (res_len == INT_MAX)
            return "";
        return s.substr(res_l, res_len);
    }
};
