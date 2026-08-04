class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<int>> adj; //stores index;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q; //dist, index, level

        for (int i = 0; i < flights.size(); i++)
        {
            if (!adj.contains(flights[i][0]))
                adj[flights[i][0]] = vector<int>();
            adj[flights[i][0]].push_back(i);
        }

        for (int i : adj[src])
        {
            q.push({flights[i][2], i, 0});
        }
        set<int> visited;
        vector<vector<int>> best(n, vector<int>(k + 2, INT_MAX));
        while (!q.empty())
        {
            tuple<int,int,int> t = q.top();
            q.pop();
            int dist = get<0>(t);
            int index = get<1>(t);
            int level = get<2>(t);

            int node = flights[index][1];

            if (level > k)
                continue;
            if (dist >= best[node][level])
                continue;

            best[node][level] = dist;
            if (node == dst)
                return dist;
            for (int i : adj[node])
            {
                if (level + 1 > k)
                    continue;
                if (flights[i][2] + dist < best[flights[i][1]][level + 1])
                    q.push({flights[i][2] + dist, i, level + 1});
            }
        }
        return -1;

        
    }
};
