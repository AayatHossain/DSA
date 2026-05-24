Approach1: Using two stacks, one for the elements and another for the minimum elements.
Time complexity: O(1) for all operations
Space complexity: O(n) for the two stacks

class SpecialStack {
private:
    stack<int> s;
    stack<int> t;

public:
    SpecialStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(t.empty() || x <= t.top()){
            t.push(x);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top() == t.top()){
            t.pop();
        }
        s.pop();
    }
    
    int peek() {
        if(s.empty())return -1;
        return s.top();
        
    }
    
    int getMin() {
        if(t.empty()) return -1;
        return t.top();
    }
    
    bool isEmpty(){
        return s.size() == 0;
    }
};

Approach2: No additional space.
Time complexity: O(1) for all operations
Space complexity: O(1)

class SpecialStack {
private:
    stack<int> s;
    int mn = INT_MAX;

public:
    SpecialStack() {
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            mn = x; 
            return;
        }
        if(x < mn){
            s.push(2*x - mn);
            mn = x;
        }else{
            s.push(x);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top() < mn){
            mn = 2*mn - s.top();
        }
        s.pop();
    }
    
    int peek() {
        if(s.empty()) return -1;
        if(s.top() < mn){
            return mn;
        }
        return s.top();
        
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mn;
    }
    
    bool isEmpty() {
        return s.size() == 0;
    }
};


Approach 3: Using stack and pair, where pair has the top element and the minimum so far.
Time complexity: O(1) for all operations
Space complexity: O(n) for the stack