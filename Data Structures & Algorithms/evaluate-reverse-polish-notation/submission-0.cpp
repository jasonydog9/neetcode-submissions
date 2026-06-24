class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for (string str : tokens)
        {
            if (str != "+" &&
                str != "*" &&
                str != "/" && 
                str != "-")
                s.push(stoi(str));
            else
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                if (str == "+")
                    s.push(second + first);
                else if (str == "*")
                    s.push(second * first);
                else if (str == "/")
                    s.push(second/first);
                else if (str == "-")
                    s.push(second - first);
            }
        }
        return s.top();
    }
};
