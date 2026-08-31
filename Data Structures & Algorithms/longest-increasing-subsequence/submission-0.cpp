class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size(),1);
        int max = 1;
        for (int i = 0;i < nums.size();i++)
        {
            for (int j = i + 1; j < nums.size();j++)
            {
                int num = v[i];
                if (num == v[j] && nums[j] > nums[i])
                {
                    v[j]++;
                    max = std::max(max, v[j]);
                }
            }
        }
        return max;
    }
};
