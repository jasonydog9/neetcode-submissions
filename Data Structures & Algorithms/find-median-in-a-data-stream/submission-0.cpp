class MedianFinder {
public:

    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<int>> greater;
    double median;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (num > median)
            greater.push(num);
        if (num <= median)
            less.push(num);

        while (abs((int) less.size() - (int) greater.size()) > 1)
        {
            if (less.size() > greater.size())
            {
                int num = less.top();
                less.pop();
                greater.push(num);
            }
            else if (greater.size() > less.size())
            {
                int num = greater.top();
                greater.pop();
                less.push(num);
            }
        }
        if (less.size() == greater.size())
            median = (less.top() + greater.top())/2.0;

        if (less.size() > greater.size())
            median = less.top();
        if (less.size() < greater.size())
            median = greater.top();
    }
    
    double findMedian() {
        return median;
    }
};
