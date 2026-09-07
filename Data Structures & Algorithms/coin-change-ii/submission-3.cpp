class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, 0));
        if (amount == 0)
            return 1;
        for (int i =1; i <= amount; i++)
        {
            int num = i;
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins[j];
                if (num ==coin)
                {
                    memo[j][i] = 1;
                }
                else if (num < coin)
                    continue;
                else 
                {
                    int diff = num - coin;
                    int sum = 0;
                    for (int k = 0; k <= j; k++)
                    {
                        sum += memo[k][diff];
                    }
                    memo[j][i] = sum;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < coins.size();i++)
            res += memo[i][amount];
        return res;
    }
};
