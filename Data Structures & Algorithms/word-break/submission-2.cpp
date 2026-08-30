class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() -1 ; i >= 0; i--)
        {
            for (string str : wordDict)
            {
                int w = str.size();
                if (i + w <= s.size() && s.substr(i, w) == str)
                    dp[i] = dp[i + w];
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};
