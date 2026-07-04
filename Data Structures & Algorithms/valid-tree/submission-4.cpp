class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> hashMap;
        for (vector<int> v : edges)
        {
            if (!hashMap.contains(v[0]))
            {
                hashMap[v[0]] = vector<int>();
            }
            if (!hashMap.contains(v[1]))
                hashMap[v[1]] = vector<int>();

            hashMap[v[0]].push_back(v[1]);
            hashMap[v[1]].push_back(v[0]);
        }
        if (edges.size() == 0)
            return true;
        queue<int> q;
        q.push(edges[0][0]);
        map<int, int> colors;
        colors[edges[0][0]] = -1;
        set<int> visited;
        int count = 0;
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            count++;
            for (int i : hashMap[num])
            {
                if (!colors.contains(i))
                {
                    colors[i] = num;
                    q.push(i);
                }
                else if (i != colors[num])
                    return false;
            }
        }
        return count == n;
    }
};
