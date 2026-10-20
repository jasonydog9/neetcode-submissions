class Solution {
public:
    int maximumSwap(int num) {
        int res = num; 
        string n = to_string(num);
        for (int i = 0; i < n.size(); i++)
        {
            for (int j = i + 1; j < n.size(); j++)
            {
                int new_num = num;
                string s = to_string(new_num);
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                new_num = stoi(s);
                res = max(res, new_num);
            }
        }
        return res;
    }
};
