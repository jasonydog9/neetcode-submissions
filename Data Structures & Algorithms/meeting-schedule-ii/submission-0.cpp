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
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxTime = 0;
        for (Interval i : intervals)
        {
            maxTime = max(maxTime, i.end);
        }
        vector<int> times(maxTime);

        for (Interval i : intervals)
        {
            int start = i.start;
            int end = i.end;
            for (int s =start; s < end; s++)
            {
                times[s]++;
            }
        }
        int res = 0;
        for (int i = 0; i < times.size();i++)
        {
            res = max(res, times[i]);
        }
        return res;
    }
};
