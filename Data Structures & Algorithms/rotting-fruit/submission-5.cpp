class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int min = 100;
        vector<vector<int>> rottens;
        for (int i = 0;i < grid.size(); i++ )
        {
            for (int j =0;j < grid[i].size();j++ )
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    rottens.push_back({i,j});

            }
        }

        for (int i = 0;i < grid.size(); i++ )
        {
            for (int j =0;j < grid[i].size();j++ )
            {
                if (grid[i][j] == 2)
                    min = std::min(bfs(grid, rottens, i, j, fresh), min);
            }
        }
        if (fresh == 0)
            return 0;
        if (min == 100)
            return -1;
        return min;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>> rottens, int row, int col, int n)
    {
        std::queue<std::tuple<int, int, int>> q;
        for (vector<int> v : rottens)
        {
            q.push(std::tuple<int,int,int>(1, v[0] - 1, v[1]));
            q.push(std::tuple<int,int,int>(1, v[0] + 1, v[1]));
            q.push(std::tuple<int,int,int>(1, v[0], v[1] + 1));
            q.push(std::tuple<int,int,int>(1, v[0], v[1] - 1));
        }
        int fresh = 0;
        int min = 0;
        std::set<std::pair<int,int>> visited;
        while (!q.empty())
        {
            std::tuple<int,int,int> elem = q.front();
            q.pop();
            int level = std::get<0>(elem);
            int new_row = std::get<1>(elem);
            int new_col = std::get<2>(elem);
            std::pair<int,int> new_pair(new_row, new_col);

            if (new_row < 0 || new_row >= grid.size() || new_col < 0 || new_col >= grid[row].size())
                continue;
            if (grid[new_row][new_col] != 1 || visited.contains(new_pair))
                continue;
            visited.insert(new_pair);
            fresh++;
            min = std::max(level, min);
            q.push(std::tuple<int,int,int>(level + 1, new_row - 1, new_col));
            q.push(std::tuple<int,int,int>(level + 1, new_row + 1, new_col));
            q.push(std::tuple<int,int,int>(level + 1, new_row, new_col + 1));
            q.push(std::tuple<int,int,int>(level + 1, new_row, new_col - 1));   
        }
        if (n == fresh)
            return min;
        return 100;


    }
};
