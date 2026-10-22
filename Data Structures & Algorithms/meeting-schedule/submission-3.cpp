/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0)
            return true;
        vector<vector<int>> v;
        for (Interval i : intervals)
            v.push_back({i.start, i.end});
        sort(v.begin(), v.end());
        for (int i = 0;i < v.size() - 1; ++i)
        {
            if (v[i][1] > v[i+1][0])
                return false;
        }
        return true;
    }
};
