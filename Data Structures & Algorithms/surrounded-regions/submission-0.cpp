class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size();i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'O' &&
                   i != 0 && j != 0 && i != board.size() - 1
                   && j != board[i].size() - 1)
                   bfs(board, i,j);
            }
        }
    }
    
    void bfs(vector<vector<char>>& board, int row, int col)
    {
        std::queue<std::pair<int, int>> q;
        std::set<std::pair<int,int>> visited;
        q.push(std::pair<int,int>(row, col));
        while (!q.empty())
        {
            std::pair<int,int> p = q.front();
            q.pop();
            int new_row = p.first;
            int new_col = p.second;

            if (new_row < 0 || new_row >= board.size() || new_col <0 || new_col >= board[row].size())
                continue;
            if (visited.contains({new_row, new_col}))
                continue;
            visited.insert({new_row, new_col});
            if (board[new_row][new_col] == 'X')
                continue;
            if ((new_row == 0 || new_row == board.size() - 1))
                return;
            if ((new_col == 0 || new_col == board[new_row].size() - 1))
                return;
            q.push({new_row + 1,new_col});
            q.push({new_row - 1,new_col});
            q.push({new_row,new_col + 1});
            q.push({new_row,new_col - 1});
        }
        for (std::pair<int,int> p : visited)
        {
            board[p.first][p.second] = 'X';
        }
        return;


    }
};
