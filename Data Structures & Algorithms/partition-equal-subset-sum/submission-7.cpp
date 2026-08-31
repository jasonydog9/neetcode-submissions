class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
        {
            sum+=i;
        }
        if (sum%2 == 1)
            return false;
        vector<bool> v(sum/2 + 1);
        v[0] = true;
        for (int i = nums.size() - 1; i >= 0;i--)
        {
            if (nums[i] > sum/2)
                return false;
            for (int j = sum/2; j >= nums[i]; j--)
            {
                if (v[j - nums[i]])
                {
                    v[j] = true;
                }
            }
        }
        return v[sum/2];
    }
};
