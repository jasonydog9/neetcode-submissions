class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        if (nums.size() == 1)
            return nums[0];
        v[0] = nums[0];
        v[1] = nums[1];

        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 2 < nums.size())
                v[i+2] = max(v[i+2], v[i] + nums[i+2]);
            if (i + 3 < nums.size())
                v[i+3] = max(v[i+3], v[i] + nums[i+3]);
        }
        return max(v[nums.size() - 1], v[nums.size() - 2]);
    }
};
