class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (vector<int> v : prerequisites)
        {
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int fin = 0;
        while (!q.empty())
        {
            int e = q.front();
            q.pop();
            fin++;
            for (int nei : adj[e])
            {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        return fin == numCourses;
    }
};
