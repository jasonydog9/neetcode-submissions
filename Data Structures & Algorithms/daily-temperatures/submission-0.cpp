class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int count = 0;
        vector<int> res(temperatures.size());
        stack<int> s;
        for (int i : temperatures)
        {
            while (s.size() > 0 && i > temperatures[s.top()])
            {
                res[s.top()] = count - s.top();
                s.pop();
            }
            s.push(count);
            count++;
        }
        return res;
    }
};
