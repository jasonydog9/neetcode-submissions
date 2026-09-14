class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<tuple<int,int>> s;
        int res = 0;
        s.push(make_tuple(0, heights[0]));
        res = max(res, heights[0]);
        for (int i = 1; i < heights.size(); i++)
        {
            int last_idx = get<0>(s.top());
            int last_height = get<1>(s.top());
            if (heights[i] < last_height)
            {
                res = max(res, (i - last_idx + 1) * heights[i]);
                int new_idx = get<0>(s.top());
                int new_height = get<1>(s.top());
                while (new_height >= heights[i])
                {
                    res = max(res, (last_idx - new_idx + 1) * new_height);
                    s.pop();
                    if (s.empty() || get<1>(s.top()) < heights[i])
                        break;
                    new_idx = get<0>(s.top());
                    new_height = get<1>(s.top());
                }
                s.push(make_tuple(new_idx, heights[i]));
                res = max(res, (i - new_idx + 1) * heights[i]);
            }
            else
            {
                s.push(make_tuple(i, heights[i]));
                res = max(res, heights[i]);
            }
        }
        while (s.size() > 0)
        {
            res = max((int) (heights.size() - 1 - get<0>(s.top()) + 1) * get<1>(s.top()), res);
            s.pop();
        }
        return res;


    }
};
