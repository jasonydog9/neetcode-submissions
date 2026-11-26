class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++) a[i + 1] = nums[i];

        vector<vector<int>> memo(n+2, vector<int>(n+2, 0));

        for (int length = 2; length <= nums.size() + 1; length++)
        {
            for (int i = 0; i <= nums.size() - length + 1 ;i++)
            {
                int r = i + length;
                for (int k = i + 1; k < r;k++)
                {
                    memo[i][r] = max(memo[i][r], memo[i][k] + memo[k][r] + a[i] * a[k] * a[r]);
                }
                
            }
        }
        return memo[0][n+1];
    }
};
