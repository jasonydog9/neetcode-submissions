class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount + 1);
        v[0] = 0;
        for (int i : coins)
        {
            if (i <= amount)
                v[i] = 1;
        }

        for (int i = 1; i < amount + 1; i++)
        {
            if (v[i] != 0)
                continue;
            int min = std::numeric_limits<int>::max();
            for (int c : coins)
            {
                if (c > i)
                    continue;
                if (v[i-c] == std::numeric_limits<int>::max())
                    continue;
                min = std::min(min, v[i-c] + 1);
            }
            v[i] = min;
        }
        if (v[amount] == std::numeric_limits<int>::max())
            return -1;
        return v[amount];

    }
};
