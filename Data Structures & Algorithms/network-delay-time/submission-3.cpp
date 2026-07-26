class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        map<int, vector<pair<int,int>>> adj;
        vector<int> dists(n + 1, -1);
        set<int> visited;
        dists[0] = 0;

        for (vector<int> v : times)
        {
            if (!adj.contains(v[0]))
                adj[v[0]] = vector<pair<int,int>>();
            adj[v[0]].push_back(make_pair(v[2], v[1]));
        }

        q.push({0, k});
        while (!q.empty())
        {
            pair<int,int> val = q.top();
            q.pop();
            int dist = val.first;
            int num = val.second;
            if (visited.count(num))
                continue;
            visited.insert(num);
            dists[num] = dist;
            for (pair<int,int> p : adj[num])
            {
                if (visited.count(p.second))
                    continue;
                int new_dist = p.first + dist;
                q.push({new_dist, p.second});
            }
        }

        int max = 0;
        for (int i : dists)
        {
            if (i == -1)
                return -1;
            max = std::max(i, max);
        }
        return max;


    }
};
