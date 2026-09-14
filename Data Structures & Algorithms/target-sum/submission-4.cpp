class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        vector<vector<int>> memo(nums.size(), vector<int>(sum * 2+ 1, 0));

        for (int i= 0; i < nums.size(); i++)
        {
            for (int j = 0; j < memo[i].size(); j++)
            {
                if (i == 0)
                {
                    memo[i][-nums[i] + sum] += 1;
                    memo[i][nums[i] + sum] += 1;
                    break;
                }
                else 
                {
                    if (memo[i-1][j] != 0)
                    {
                        int old = memo[i-1][j];
                        if (j - nums[i] >= 0)
                            memo[i][j - nums[i]] += old;
                        if (j + nums[i] <= 2 * sum)
                            memo[i][j + nums[i]] += old;
                    }
                }

            }
        }
        if (target > sum || target < -sum) return 0;
        return memo[nums.size() -1][target + sum];
    }
};
