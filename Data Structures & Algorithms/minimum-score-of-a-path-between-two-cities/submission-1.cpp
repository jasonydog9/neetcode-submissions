class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<tuple<int,int>>> adj(n+1, vector<tuple<int,int>>());
        for (vector<int> v : roads)
        {
            adj[v[0]].push_back({v[2], v[1]});
            adj[v[1]].push_back({v[2], v[0]});
        }

        queue<tuple<int, int>> q;
        int res = INT_MAX;
        vector<bool> visited(n+1);
        q.push({INT_MAX, 1});
        while (!q.empty())
        {
            int ele = get<1>(q.front());
            int dist = get<0>(q.front());
            q.pop();
            res = min(dist, res);
            if (visited[ele])
                continue;
            visited[ele] = true;

            for (tuple<int,int> t : adj[ele])
            {
                q.push(t);
            }
        }
        return res;
    }
};
