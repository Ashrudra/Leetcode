class MinStack {
private:
    std::stack<int> s;
    std::stack<int> minS;

public:
    MinStack() {
    }
    
    void push(int value) {
        s.push(value);
        if (minS.empty() || value <= minS.top()) {
            minS.push(value);
        }
    }
    
    void pop() {
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
