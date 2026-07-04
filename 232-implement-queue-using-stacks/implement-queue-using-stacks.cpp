class MyQueue {
private:
    // inputStack is used to push new elements in
    std::stack<int> inputStack;
    // outputStack is used to pop or peek elements (front of queue)
    std::stack<int> outputStack;

    // Helper function to move elements from inputStack to outputStack
    // This is only called when outputStack is empty
    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor: Nothing needed, stacks are initialized automatically
    }
    
    // Push element x to the back of the queue
    // Time Complexity: O(1)
    void push(int x) {
        inputStack.push(x);
    }
    
    // Removes the element from the front of the queue and returns it
    // Time Complexity: Amortized O(1)
    int pop() {
        // Ensure the elements are in the outputStack
        transferIfNeeded();
        
        int frontValue = outputStack.top();
        outputStack.pop();
        return frontValue;
    }
    
    // Returns the element at the front of the queue
    // Time Complexity: Amortized O(1)
    int peek() {
        // Ensure the elements are in the outputStack
        transferIfNeeded();
        
        return outputStack.top();
    }
    
    // Returns whether the queue is empty
    // Time Complexity: O(1)
    bool empty() {
        // Queue is empty only if both stacks are empty
        return inputStack.empty() && outputStack.empty();
    }
};
