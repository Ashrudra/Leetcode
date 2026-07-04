class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = s.top();
                s.pop();
                long long a = s.top();
                s.pop();
                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else s.push(a / b);
            } else {
                s.push(stoll(token));
            }
        }
        return (int)s.top();
    }
};
