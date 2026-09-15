class Solution {
public:
    vector<vector<int>> memo;
    int rows, cols;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        memo.assign(rows, vector<int>(cols, 0));

        int res = 1;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res = max(res, dfs(i, j, matrix));

        return res;
    }

    int dfs(int row, int col, vector<vector<int>>& matrix)
    {
        if (memo[row][col] != 0)
            return memo[row][col];

        int best = 1;
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                matrix[nr][nc] > matrix[row][col])
            {
                best = max(best, 1 + dfs(nr, nc, matrix));
            }
        }

        memo[row][col] = best;
        return best;
    }
};