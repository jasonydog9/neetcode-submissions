class Solution {
public:
vector<vector<bool>> memo;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        memo.resize(heights.size(), vector<bool>(heights[0].size(), false));
        for (int i = 0;i < heights.size(); i++)
        {
            for (int j = 0; j < heights[i].size();j++)
            {
                vector<bool> atlanticpacific(2, false);
                vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
                visited[i][j] = true;
                dfs(i, j, visited, heights, atlanticpacific);
                if (atlanticpacific[0] && atlanticpacific[1])
                {
                    memo[i][j] = true;
                    vector<int> v{i,j};
                    res.push_back(v);
                }
            }
        }
        return res;
    }


    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& heights, vector<bool>& atlanticpacific)
    {
        if (row == heights.size() - 1 || col == heights[row].size() - 1)
        {
            atlanticpacific[0] = true;
        }
        if (row == 0 || col == 0)
        {
            atlanticpacific[1] = true;
        }
        if (memo[row][col])
        {
            atlanticpacific[0] = true;
            atlanticpacific[1] = true;
        }
        if (atlanticpacific[0] && atlanticpacific[1])
        {
            return;
        }

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        for (int i = 0; i < 4; i++)
        {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            if (new_row >= 0 && new_row < heights.size() && new_col >= 0 && new_col < heights[row].size())
            {
                if (heights[new_row][new_col] <= heights[row][col] && !visited[new_row][new_col])
                {
                    visited[new_row][new_col] = true;
                    dfs(new_row, new_col, visited, heights, atlanticpacific);
                }
            }
        }
    }
};
