class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> q;

        vector<bool> visited(points.size());
        q.push({0, 0});
        int res = 0;
        int connected = 0;


        while (!q.empty() && connected < points.size())
        {
            auto [added_dist, index] = q.top();
            q.pop();
            if (visited[index])
                continue;
            visited[index] = true;
            pair<int,int> p = {points[index][0], points[index][1]};
            res += added_dist;
            connected++;
            for (int i = 0; i < points.size(); i++)
            {
                if (i == index)
                    continue;
                int dist = abs(p.first - points[i][0]) + abs(p.second - points[i][1]);
                q.push({dist, i});
            }
        }
        return res;
    }
};