class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        vector<int> indegree(numCourses);
        for (int i  =0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            indegree[b]++;
            adj[a].push_back(b);
        }

        queue<int> q;
        for (int i = 0; i < indegree.size();i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int num = 0;
        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            num++;
            for (int i : adj[idx])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        return num == numCourses;

    }
};
