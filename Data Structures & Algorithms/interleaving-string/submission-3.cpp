class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.empty() && s2.empty()) return s3.empty();
        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;

        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<string>> memo(s2.size() + 1, vector<string>(s1.size() + 1, ""));

        for (int i = 0; i < memo.size(); i++)
        {
            for (int j = 0; j < memo[i].size(); j++)
            {
                string prev1 = "";
                if (j > 0)
                {
                    prev1 = memo[i][j - 1];
                    if (s1.substr(j-1, 1) != "" && prev1 + s1.substr(j - 1, 1) == s3.substr(0, j + i))
                    {
                        memo[i][j] = prev1 + s1.substr(j - 1, 1);
                    }
                }
                string prev2 = "";
                if (i > 0)
                {
                    prev2 = memo[i-1][j];
                    if (s2.substr(i - 1, 1) != "" && prev2 + s2.substr(i - 1, 1) == s3.substr(0, j + i))
                    {
                        memo[i][j] = prev2 + s2.substr(i - 1, 1);
                    }
                }
            }
        }
        return memo[s2.size()][s1.size()] != "";
    }
};
