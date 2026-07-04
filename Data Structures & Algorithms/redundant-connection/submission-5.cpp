class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        vector<int> indegree(edges.size() + 1, 0);
        for (vector<int> v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
            indegree[v[1]]++;
        }

        queue<int> q;
        for (int i =1; i <= edges.size();i++)
        {
            if (indegree[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            indegree[ele]--;
            for (int nei : adj[ele])
            {
                indegree[nei]--;
                if (indegree[nei] == 1)
                    q.push(nei);
            }
        }
        for (int i = edges.size() - 1; i >= 0; i-- )
        {
            int one = edges[i][0];
            int sec = edges[i][1];
            if (indegree[one] == 2 && indegree[sec])
                return edges[i];
        }
        return {};




    }
};
