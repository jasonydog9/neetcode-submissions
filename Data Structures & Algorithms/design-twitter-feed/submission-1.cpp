class Twitter {
public:
    Twitter() {
        postCount = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        vector<int> v;
        v.push_back(postCount);
        v.push_back(userId);
        v.push_back(tweetId);
        postCount++;
        postTimes.push(v);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        std::priority_queue<vector<int>> pt = postTimes;
        while (!pt.empty() && res.size() != 10)
        {
            vector<int> v = pt.top();
            pt.pop();
            if (v[1] == userId)
                res.push_back(v[2]);
            else if (hashMap.contains(userId) && std::ranges::contains(hashMap[userId], v[1]))
                res.push_back(v[2]);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (!hashMap.contains(followerId))
            hashMap[followerId] = vector<int>();
        hashMap[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!hashMap.contains(followerId))
            return;
        std::erase(hashMap[followerId], followeeId);
    }

private:
    int postCount;
    std::priority_queue<vector<int>> postTimes;
    map<int, vector<int>> hashMap;
};
