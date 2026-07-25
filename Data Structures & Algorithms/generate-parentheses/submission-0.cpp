class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string curr;
        dfs(0,0,n, curr);
        return res;
    }

    void dfs(int open, int closed, int n, string curr)
    {
        if (open > n || closed > open)
            return;
        if (closed == n)
        {
            res.push_back(curr);
            return;
        }
        curr+= "(";
        dfs(open + 1, closed, n, curr);
        curr.pop_back();
        curr+=")";
        dfs(open, closed + 1, n, curr);
        
    }
};
