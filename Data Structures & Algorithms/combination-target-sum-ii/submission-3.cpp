class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<int> subset;
        dfs(candidates, subset, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, vector<int> subset, int target, int index)
    {
        if (target == 0)
        {
            res.push_back(subset);
            return;
        }
        if (target <0 || index >= candidates.size())
        {
            return;
        }
        subset.push_back(candidates[index]);
        dfs(candidates, subset, target - candidates[index], index+1);
        subset.pop_back();
        int next = index + 1;
        while (next < candidates.size() && candidates[index] == candidates[next])
            next++;
        dfs(candidates, subset, target, next);
        
    }
};
