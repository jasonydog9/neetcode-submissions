class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        set<int> s;
        dfs(nums, subset, s);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> subset, set<int> s)
    {
        if (subset.size() == nums.size())
        {
            res.push_back(subset);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.contains(nums[i]))
            {
                continue;
            }
            s.insert(nums[i]);
            subset.push_back(nums[i]);
            dfs(nums, subset, s);
            s.erase(nums[i]);
            subset.pop_back();
        }
    }
};
