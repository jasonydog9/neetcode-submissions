class LRUCache {
public:

    std::list<int> cache;
    unordered_map<int, pair<int, std::list<int>::iterator>> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.contains(key))
        {
            int res = mp[key].first;
            std::list<int>::iterator it = mp[key].second;
            cache.erase(it);
            cache.push_back(key);
            mp[key] = {res, --cache.end()};
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //if element exists in the map then do something

        if (mp.contains(key))
        {
            std::list<int>::iterator it = mp[key].second;
            cache.erase(it);
            mp.erase(key);
        }
        else if (cache.size() == cap)
        {
            mp.erase(cache.front());
            cache.pop_front();
        }
        cache.push_back(key);
        mp[key] = {value, --cache.end()};
        //if element doesn't exist then add if size is not capacity
    }


    //old -> new -> new
};
