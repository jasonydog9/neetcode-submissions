class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> hashMap;
        int max = -10000;
        vector<int> res;
        priority_queue<int> pq;
        if (k ==1 )
            return nums;
        for (int i = 0; i < k; i++)
        {
            hashMap[nums[i]]++;
            max = std::max(max, nums[i]);
            pq.push(nums[i]);
        }       
        res.push_back(max);
        int l = 0;
        int r = k;
        while (r < nums.size())
        {
            hashMap[nums[l]]--;
            if (hashMap[nums[l]] == 0 && max == nums[l])
            {
                pq.pop();
                while (hashMap[pq.top()] == 0 && pq.size() >0 )
                {
                    pq.pop();
                }
                max = pq.top();
            }
            l++;

            hashMap[nums[r]]++;
            max = std::max(nums[r], max);
            res.push_back(max);
            pq.push(nums[r]);
            r++;
        }

        return res;

        
    }
};
