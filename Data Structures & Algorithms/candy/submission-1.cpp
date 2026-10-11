class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1);
        int prevCount = 0;
        int count = ratings.size();
        while (prevCount != count)
        {
            prevCount = count;
            for (int i = 1; i <ratings.size(); i++)
            {
                int num = ratings[i];
                if (num < ratings[i-1] && res[i] >= res[i-1])
                {
                    int temp = res[i-1];
                    res[i-1] = res[i] + 1;
                    count += (res[i-1] - temp);
                }
                if (num > ratings[i-1] && res[i] <= res[i-1])
                {
                    int temp = res[i];
                    res[i] = res[i-1] + 1;
                    count += (res[i] - temp);
                }
            }
        }
        return count;
    }
};