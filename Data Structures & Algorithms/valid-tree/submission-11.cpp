class Solution {
public:

    vector<int> parent;
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int resX = find(x);
        int resY = find(y);
        if (resX == resY)
            return false;
        parent[resY] = resX;
        return true;
    }



    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        for (vector<int> edge : edges)
        {
            int out = edge[0];
            int in  = edge[1];
            if (!unite(out, in))
                return false;
        }
        int val = parent[0];
        for (int i : parent)
        {
            if (find(i) != find(val))
                return false;
        }
        return true;
    }   
};
