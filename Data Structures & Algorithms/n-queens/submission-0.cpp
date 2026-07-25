class Solution {
public:

    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string>& board, int index)
    {
        if (index >= board.size())
        {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (!check(board, i, index))
                continue;
            board[i][index] = 'Q';
            backtrack(board, index + 1);
            board[i][index] = '.';
        }

    }



    bool check(vector<string>& board, int row, int col)
    {   
        for (int i = col - 1; i >= 0; i--)
        {
            if (board[row][i] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col -1; i>=0 && j>=0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row + 1, j = col -1; i<board.size() && j>=0; i++, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
