class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        q.push({grid[0][0], 0,0});

        int max = grid[0][0];
        while (!q.empty())
        {
            tuple<int,int,int> ele = q.top();
            int row = get<1>(ele);
            int col = get<2>(ele);
            int val = get<0>(ele);
            q.pop();
            if (visited[row][col])
                continue;
            visited[row][col] = true;
            max = std::max(max, val);
            if (row == grid.size() - 1 && col == grid[0].size() - 1)
                break;


            int rows = grid.size();
            int cols = grid[0].size();

            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for (int d = 0; d < 4; d++) {
                int nr = row + dr[d];
                int nc = col + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    q.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return max;
    }
};
