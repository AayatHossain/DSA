Approach1: Using two stacks
Time complexity: O(1) for push and pop operations
Space complexity: O(1) 

class twoStacks {
  public:
    stack<int> s1;
    stack<int> s2;
    

    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        s1.push(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        
        // code here
        s2.push(x);
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(s1.empty())return -1;
        int v = s1.top();
        s1.pop();
        return v;
        // code here
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
         if(s2.empty())return -1;
        int v = s2.top();
        s2.pop();
        return v;
    }
};