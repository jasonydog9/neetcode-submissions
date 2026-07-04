class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (vector<int> v : prerequisites)
        {
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                res.push_back(i);
            }
        }

        int finished = 0;
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            finished++;
            for (int nei : adj[ele])
            {
                indegree[nei]--;
                if (indegree[nei] == 0)
                {
                    q.push(nei);
                    res.push_back(nei);
                }
            }
        }
        std::reverse(res.begin(), res.end());
        if (finished == numCourses)
            return res;
        return std::vector<int>();
    }
};
