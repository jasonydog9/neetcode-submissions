class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(), vector<int>(t.size(), 0));

        for (int j = 0; j < t.size(); j++)
        {
            for (int i = 0; i < s.size(); i++)
            {
                char cs = s[i];
                char ct = t[j];
                int above = 0;
                int diag = 0;

                if (i < j)
                    continue;

                if (i > 0)
                    above = memo[i-1][j];
                if (i > 0 && j > 0)
                    diag = memo[i-1][j-1];
                else if (j == 0)
                    diag = 1;

                if (cs == ct)
                {
                    memo[i][j] = above + diag;
                }
                else
                    memo[i][j] = above;
            }
        }
        return memo[s.size()-1][t.size()-1];
    }
};
