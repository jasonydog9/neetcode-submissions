class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1);
        memo[0] = 1;
        for (int i = 1; i < memo.size();i++)
        {
            for (int num : nums)
            {
                int diff = i - num;
                if (diff >= 0)
                {
                    memo[i] += memo[diff];
                }
            }
        }
        return memo[target];
    }
};