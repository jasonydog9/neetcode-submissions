class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        stack<double> s;
        for (std::pair<int, int> p : pair)
        {
            double time = (static_cast<double>(target) - p.first)/p.second;
            if (s.size() == 0 || s.top() < time)
            {
                s.push(time);
            }
        }
        return s.size();
    }
};
