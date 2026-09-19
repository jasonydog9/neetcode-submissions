class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < word2.size() + 1;i++)
        {
            memo[word1.size()][i] = word2.size() - i;
        }

        for (int i = 0; i < word1.size() + 1;i++)
        {
            memo[i][word2.size()] = word1.size() - i;
        }

        for (int i = word1.size()- 1; i>= 0; i--)
        {
            for (int j = word2.size() - 1; j >= 0; j--)
            {
                char c1 = word1.at(i);
                char c2 = word2.at(j);

                int min = std::min(std::min(memo[i+1][j+1], memo[i+1][j]), memo[i][j+1]);

                if (c1 != c2)
                {
                    min += 1;
                    memo[i][j] = min;
                }
                else
                    memo[i][j] = memo[i+1][j+1];
            }
        }

        return memo[0][0];
    }
};
