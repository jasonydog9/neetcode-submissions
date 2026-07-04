class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        for (vector<int> v : edges)
        {   
            if (!adj.contains(v[0]))
                adj[v[0]] = vector<int>();
            if (!adj.contains(v[1]))
                adj[v[1]] = vector<int>();

            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int count = 0;
        set<int> visited;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!visited.contains(i))
                count++;
            q.push(i);
            while (!q.empty())
            {
                int ele = q.front();
                q.pop();

                if (visited.contains(ele))
                    continue;
                visited.insert(ele);
                for (int nei : adj[ele])
                {
                    q.push(nei);
                }
            }
        }
        return count;
    }
};
