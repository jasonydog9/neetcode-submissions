class LRUCache {
public:
    LRUCache(int capacity) {

        c = capacity;
    }
    
    int get(int key) {
        if (!hashMap.contains(key))
            return -1;

        order.erase(hashMap[key].second);
        order.push_back(key);
        hashMap[key] = {hashMap[key].first, --order.end()};
        return hashMap[key].first;
    }
    
    void put(int key, int value) {
        if (hashMap.contains(key))
        {
            order.erase(hashMap[key].second);
        }
        else if (c == order.size())
        {
            int o = order.front();
            order.pop_front();
            hashMap.erase(o);
        }
        order.push_back(key);
        hashMap[key] = {value, --order.end()};

    }
private:
map<int, pair<int, list<int>::iterator>> hashMap;
std::list<int> order;
int c;
};
