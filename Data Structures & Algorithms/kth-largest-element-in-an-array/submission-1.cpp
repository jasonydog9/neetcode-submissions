class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> q;
        for (int i : nums)
        {
            q.push(i);
            if (q.size() > k)
                q.pop();
        }
       
        return q.top();
    }
};
