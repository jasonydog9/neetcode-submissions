class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> q;

        for (vector<int> v : points)
        {
            int dist = v[0] * v[0] + v[1] * v[1];
            q.push({dist, v[0], v[1]});
        }

        vector<vector<int>> res;

        while (res.size() != k)
        {
            auto top = q.top();
            q.pop();
            res.push_back({top[1], top[2]});
        }
        return res;
    }
};