class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, vector<int>(), res);
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int> subset, vector<vector<int>>& res)
    {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);
        subset.pop_back();
        dfs(nums, i + 1, subset, res);
    }


};
