class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        map<char,int> freq;
        for (char c : tasks)    
        {
            freq[c]++;
        }
        for (auto& [key, val] : freq)
        {
            pq.push(make_pair(val, key));
        }
        int count = 0;
        while (!pq.empty())
        {
            vector<pair<int,char>> v;
            pair<int, char> p = pq.top();
            int num = p.first - 1;
            char c = p.second;
            pq.pop();
            if (num != 0)
                v.push_back(make_pair(num, c));
            count++;
            for (int i = 0; i < n;i++)
            {
                if (pq.size() == 0 && v.size() == 0)
                    break;
                if (pq.size() > 0)
                {
                    int num1 = pq.top().first - 1;
                    char c1 = pq.top().second;
                    pq.pop();
                    if (num1 != 0)
                        v.push_back(make_pair(num1, c1));
                }
                count++;
            }
            for (pair<int, char> p : v)
            {
                pq.push(p);
            }
        }
        return count;
    }
};
