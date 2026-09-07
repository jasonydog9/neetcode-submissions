class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, 0));
        vector<vector<int>> prefix(coins.size(), vector<int>(amount + 1, 0));

        if (amount == 0)
            return 1;

        for (int i = 1; i <= amount; i++)
        {
            int num = i;

            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins[j];

                if (num == coin)
                {
                    memo[j][i] = 1;
                }
                else if (num > coin)
                {
                    int diff = num - coin;

                    // replaces:
                    // for (int k = 0; k <= j; k++)
                    //     sum += memo[k][diff];

                    memo[j][i] = prefix[j][diff];
                }

                // prefix[j][i] = memo[0][i] + ... + memo[j][i]
                prefix[j][i] = memo[j][i];

                if (j > 0)
                    prefix[j][i] += prefix[j - 1][i];
            }
        }

        return prefix[coins.size() - 1][amount];
    }
};