class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> subset;
        backtrack(s, 0, subset);
        return res;
    }

    void backtrack(string s, int index, vector<string> subset)
    {
        if (index >= s.size()) 
        {
            res.push_back(subset);
            return;
        }
        
        for (int i = index + 1; i <= s.size(); i++)
        {
            string sub = s.substr(index, i - index);
            if (!isPalindrome(sub))
                continue;
            subset.push_back(sub);
            backtrack(s, i, subset);
            subset.pop_back();
        }
        
    }

    bool isPalindrome(string str)
    {
        int l = 0;
        int r = str.size() -1;

        while (l < r)
        {
            if (str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;

    }
};
