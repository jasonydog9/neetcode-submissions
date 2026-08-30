class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrev = nums[0];
        int minPrev = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i <nums.size(); i++)
        {
            int temp = min(min(minPrev * nums[i], maxPrev * nums[i]), nums[i]);
            maxPrev = max(max(maxPrev * nums[i], minPrev * nums[i]), nums[i]);
            minPrev = temp;
            globalMax = max(globalMax, maxPrev);
        }
        return globalMax;
    }
};
