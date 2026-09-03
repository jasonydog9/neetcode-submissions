class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> cache(prices.size());
        int max = 0;

        for (int i = prices.size() - 1; i >= 0; i--)//buy
        {
            for (int j = prices.size() - 1; j>=i; j--)//sell
            {
                int buy = i;
                int sell = j;

                int add = 0;
                if (sell  + 2 < prices.size())
                {
                    add = cache[sell + 2];
                }
                if (sell + 3 < prices.size())
                    add = std::max(cache[sell+3], add);
                add += (prices[sell] - prices[buy]);
                cache[i] = std::max(cache[i], add);
            }       
            max = std::max(cache[i], max);
        }   
        return max;
    }
};
