class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                set<pair<int,int>> s;
                if (backtrack(board, 0, {i,j}, s, word))    
                    return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, int index, pair<int,int> c, set<pair<int,int>> s, string word)
    {
        int row = c.first;
        int col = c.second;
        if (s.contains(c) || row < 0 || row >= board.size() || 
        col < 0 || col >= board[board.size() - 1].size())
            return false;
        
        if (word[index] != board[row][col])
            return false;
        s.insert(c);
        if (index == word.size() - 1)
            return true;

        pair<int,int> new_pair(row + 1, col);
        bool res1 = backtrack(board, index + 1, new_pair, s, word);
        new_pair = {row - 1, col};
        bool res2 = backtrack(board, index + 1, new_pair, s, word);
        new_pair = {row, col -1};
        bool res3 = backtrack(board, index + 1, new_pair, s, word);
        new_pair = {row, col + 1};
        bool res4 = backtrack(board, index + 1, new_pair, s, word);

        return res1 || res2 || res3 || res4;





    }
};
