class Solution {
public:
    vector<string> res;
    map<string, vector<char>> mapping;
    vector<string> letterCombinations(string digits) {
        mapping["2"] = {'a','b','c'};
        mapping["3"] = {'d','e','f'};
        mapping["4"] = {'g', 'h', 'i'};
        mapping["5"] = {'j', 'k', 'l'};
        mapping["6"] = {'m', 'n', 'o'};
        mapping["7"] = {'p', 'q', 'r', 's'};
        mapping["8"] = {'t', 'u', 'v'};
        mapping["9"] = {'w', 'x', 'y', 'z'};
        string sub;
        backtrack(digits, sub, 0);
        return res;
    }

    void backtrack(string digits, string sub, int index)
    {
        if (sub.size() == digits.size())
        {
            if (sub.size() == 0)
                return;
            res.push_back(sub);
            return;
        }

        string c = digits.substr(index,1 );
        for (int i = 0;i < mapping[c].size(); i++)
        {
            sub+=mapping[c][i];
            backtrack(digits, sub, index + 1);
            sub.pop_back();
        }

    }


};
