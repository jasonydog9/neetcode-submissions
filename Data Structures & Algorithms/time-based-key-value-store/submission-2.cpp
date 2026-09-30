class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";
        const auto& v = it->second;

        int l = 0;
        int r = v.size() - 1;
        while (l <= r)
        {
            int mid = (l + r)/2;
            if (v[mid].first == timestamp)
            {
                return v[mid].second;
            }
            else if (v[mid].first > timestamp)
                r = mid -1;
            else
                l = mid + 1;
        }
        if (l - 1 >= 0)
            return v[l -1].second;
        return "";
    }
};
