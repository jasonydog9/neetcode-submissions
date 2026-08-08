class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v(cost.size() + 1);
        v[0] = 0;
        v[1] = cost[0];
        for (int i =2; i < cost.size() + 1; i++)
        {
            v[i] = min(v[i-1], v[i-2]) + cost[i - 1];
        }

        return min(v[cost.size()], v[cost.size() - 1]);
    }
};
