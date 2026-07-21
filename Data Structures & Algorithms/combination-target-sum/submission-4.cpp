class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, subset, 0, 0, target, res);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> subset, int curr, int index, int target, vector<vector<int>>& res)
    {
        if (curr == target)
        {
            res.push_back(subset);
            return;
        }
        if (index >= nums.size() || curr > target)
        {
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums, subset, curr + nums[index], index, target,res);
        subset.pop_back();
        dfs(nums, subset, curr, index + 1, target,res);
    }
};
