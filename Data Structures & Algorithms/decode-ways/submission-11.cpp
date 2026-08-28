class Solution {
public:
    int numDecodings(string s) {
        vector<int> v(s.size());
        if (s.size() == 0 || s[0] == '0')
            return 0;
        v[0] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            char prev = s[i - 1];
            char curr = s[i];
            if (curr != '0')
            { 
                v[i] = v[i-1];
            }
            if (prev == '1' || (prev=='2' && curr <= '6'))
            {
                if (i >= 2)
                    v[i] += v[i - 2];
                else
                    v[i] += 1;
            }
        }
        return v[s.size()-1];
    }
};
