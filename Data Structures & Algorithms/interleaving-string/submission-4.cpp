class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.empty() && s2.empty()) return s3.empty();
        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;

        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<bool>> memo(s2.size() + 1, vector<bool>(s1.size() + 1, false));
        memo[0][0] = true;

        for (int i = 0; i < memo.size(); i++)
        {
            for (int j = 0; j < memo[i].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;

                bool ok = false;
                if (j > 0)
                {
                    if (memo[i][j - 1] && s1[j - 1] == s3[i + j - 1])
                        ok = true;
                }
                if (i > 0)
                {
                    if (memo[i - 1][j] && s2[i - 1] == s3[i + j - 1])
                        ok = true;
                }
                memo[i][j] = ok;
            }
        }
        return memo[s2.size()][s1.size()];
    }
};