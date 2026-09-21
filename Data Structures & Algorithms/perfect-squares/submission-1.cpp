class Solution {
public:
    int numSquares(int n) {
        
        int i = 1;
        vector<int> nums;
        while (i*i <= n)
        {
            nums.push_back(i * i);
            i++;
        }

        vector<int> memo(n+1, std::numeric_limits<int>::max());
        memo[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int num : nums)
            {
                int diff = i - num;
                if (diff >= 0)
                {
                    memo[i] = min(memo[diff] + 1, memo[i]);
                }
            }
        }
        return memo[n];
    }
};