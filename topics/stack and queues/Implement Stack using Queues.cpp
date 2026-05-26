Link: https://leetcode.com/problems/implement-stack-using-queues/description/
Approach1: Using one queue
Time complexity: O(n) for push operation and O(1) for pop and top operations
Space complexity: O(n) for the queue

class MyStack {
    queue<int> q;
   
public:
    
    MyStack() {
      
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++){
            int v = q.front();
            q.pop();
            q.push(v);
        }
    }
    
    int pop() {
        if(q.empty())return -1;
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(q.empty())return -1;
        int x = q.front();
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */





Approach2: Using two queues
Time complexity: O(n) for push operation and O(1) for pop and top operations
Space complexity: O(n) for the queues


class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    
    MyStack() {
      
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if(q1.empty())return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(q1.empty())return -1;
        int x = q1.front();
        return x;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */