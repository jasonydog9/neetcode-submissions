class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        int count = 0;
        for (vector<int> interval : intervals)
        {
            if (interval[0] < prevEnd)
            {
                prevEnd = min(interval[1], prevEnd);
                count++;
            }
            else
                prevEnd = interval[1];
        }
        return count - 1;
    }
};
