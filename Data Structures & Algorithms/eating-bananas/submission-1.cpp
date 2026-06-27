class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int l = 1;
        int r = piles[piles.size() - 1];
        int min = piles[piles.size() - 1];
        while (l <= r)
        {
            int mid = (l + r)/2;
            int res = check(piles, mid);
            if (res <= h)
            {
                min = std::min(min, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return min;
    }

    int check(vector<int>& piles, int k)
    {
        int sum = 0;
        for (int i : piles)
        {
            sum += std::ceil(i/static_cast<double>(k));
        }
        return sum;
    }
};
