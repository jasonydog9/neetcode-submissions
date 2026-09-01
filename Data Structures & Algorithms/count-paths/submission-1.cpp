class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n, 0));
        memo[0][0] = 1;
        for (int i =0;i < m;i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = 0;
                int top = 0;
                if (j - 1 >= 0)
                    left = memo[i][j - 1];
                if (i - 1 >= 0)
                    top = memo[i-1][j];
                memo[i][j]+=(left+top);
            }
        }
        return memo[m-1][n-1];
    }
};
