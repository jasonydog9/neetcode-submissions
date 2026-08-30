class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> hashMap;
        set<int> idxs;
        for (string str : wordDict)
        {
            hashMap[str] = 1;
        }
        idxs.insert(0);
        for (int i =1; i < s.size(); i++)
        {
            for (int idx : idxs)
            {
                if (hashMap.contains(s.substr(idx, i - idx)))
                    idxs.insert(i);
            }
        }
        for (int idx : idxs)
        {
            if(hashMap.contains(s.substr(idx)))
                return true;
        }
        return false;

    }

    /*bool stringDfs(string curr, int idx,string s, map<string, int> hashMap)
    {
        if (idx == s.size())
            return curr == "";
        
        curr += s[idx];
        idx++;
        bool res;
        if (hashMap.contains(curr))
        {
            res = stringDfs("", idx, s, hashMap);
        }
        return res || stringDfs(curr, idx, s, hashMap);
        
    }*/
};
