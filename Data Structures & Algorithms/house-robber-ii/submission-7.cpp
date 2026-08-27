class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> first(nums.size());
        vector<int> second(nums.size());
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        first[0] = nums[0];
        first[1] = nums[1];
        second[1] = nums[1];
        second[2] = nums[2];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 2 < nums.size() - 1)
            {
                first[i + 2] = max(first[i+2], nums[i+2] + first[i]);
            }
            if (i + 3 < nums.size() - 1)
            {
                first[i+3] = max(first[i+3], nums[i+3] + first[i]);
            }
            if (i+3 < nums.size())
            {
                second[i+3] = max(second[i+3], nums[i+3] + second[i + 1]);
            }
            if (i+4 < nums.size())
            {
                second[i+4] = max(second[i+4], nums[i+4] + second[i+1]);
            }
        }
        return max(first[nums.size() - 3], max(second[nums.size()-2], max(second[nums.size() - 1], first[nums.size()-2])));
    }
};
