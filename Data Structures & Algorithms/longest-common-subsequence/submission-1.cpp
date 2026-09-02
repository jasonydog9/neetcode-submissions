class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text2.size(), vector<int>(text1.size(), 0));
        memo[text2.size() - 1][text1.size() - 1] = 0;

        int max = 0;
        for (int i = text2.size()-1; i >= 0; i--)
        {
            for (int j = text1.size() - 1; j>= 0; j--)
            {
                if (text1[j] == text2[i])
                {
                    int add = 0;
                    if (i + 1 < text2.size() && j + 1 < text1.size())
                        add = memo[i + 1][j + 1];

                    memo[i][j] = add + 1;
                }
                else 
                {
                    int one = 0;
                    int two = 0;
                    if (i + 1 < text2.size())
                        one = memo[i+1][j];
                    if (j + 1 < text1.size())
                        two= memo[i][j+1];
                    memo[i][j] = std::max(one, two);
                }

                max = std::max(memo[i][j], max);
            }
        }
        return max;
    }
};
