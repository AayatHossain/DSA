class SpecialStack {
    stack<int> s;
    stack<int> smin;
  public:
    SpecialStack() {
        
    }

    void push(int x) {
        // Add an element to the top of Stack
        s.push(x);
        if(smin.empty() || (!smin.empty() && smin.top() >= x)){
            smin.push(x);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(s.empty()) return;
        int x = s.top();
        s.pop();
        if((!smin.empty() && smin.top() == x)){
            smin.pop();
        }
    }

    int peek() {
        // Returns top element of the Stack
        if(s.empty())return -1;
        return s.top();
    }

    bool isEmpty() {
        // Check if stack is empty
        return s.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        if(smin.empty()) return -1;
        return smin.top();
    }
};