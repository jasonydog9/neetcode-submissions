class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());

        for (int i = 1; i < height.size(); i++)
        {
            left_max[i] = max(height[i-1], left_max[i -1]);
            right_max[height.size() - i - 1] = max(height[height.size() - i], right_max[height.size() - i]);
        }
        int sum = 0;
        for (int i =0; i < height.size(); i++)
        {
            int min = std::min(left_max[i], right_max[i]);
            if (min - height[i] < 0)
                continue;
            sum += (min - height[i]);
        }
        return sum;
    }
};
