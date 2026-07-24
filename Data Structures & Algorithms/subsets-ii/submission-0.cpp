class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> subset;
        set<int> s;
        res.push_back(subset);
        dfs(nums, subset, s, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> subset, set<int> s, int index)
    {
        if (index >= nums.size())
        {
            return;
        }
        
        int next = index + 1;
        subset.push_back(nums[index]);
        s.insert(nums[index]);
        res.push_back(subset);
        dfs(nums, subset, s, next);
        while (next < nums.size() && nums[index] == nums[next])
        {
            next++;
        }
        subset.pop_back();
        s.erase(nums[index]);
        dfs(nums, subset, s, next);
        


    }
};
