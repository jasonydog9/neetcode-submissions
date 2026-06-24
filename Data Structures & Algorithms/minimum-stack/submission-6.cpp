class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (ex.size() == 0)
            ex.push(val);
        else if (ex.size() > 0 && val <= ex.top())
            ex.push(val);
    }
    
    void pop() {
        if (s.size() == 0)
            return;
        int val = s.top();
        s.pop();
        if (ex.size() > 0 && val == ex.top())
            ex.pop();
    }
    
    int top() {
        if (s.size() == 0)
            return -1;
        return s.top();
    }
    
    int getMin() {
        if (ex.size() == 0)
            return -1;
        return ex.top();
    }

private:
    std::stack<int> ex;
    std::stack<int> s;
    int min;
};
