class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> adj;
        vector<int> indegree(n+1);
        for (vector<int> v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
            indegree[v[1]]++;
        }

        queue<pair<int,int>> q;
        for (int i = 0; i < indegree.size();i++)
        {
            if (indegree[i] == 1)
            {
                q.push({i, 0});
                indegree[i]--;
            }
        }
        vector<int> dists(n);

        int max = 0;
        while (!q.empty())
        {
            pair<int,int> ele = q.front();
            q.pop();

            int num = ele.first;
            int dist = ele.second;
            dists[num] = dist;
            max = std::max(max, dist);

            for (int i : adj[num])
            {
                indegree[i]--;
                if (indegree[i] == 1)
                    q.push({i, dist + 1});
            }
        }
        vector<int> res;
        for (int i = 0; i < dists.size(); i++)
        {
            if (dists[i] == max)
                res.push_back(i);

        }
        return res;


    }
};