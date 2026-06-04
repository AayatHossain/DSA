Link:https://www.geeksforgeeks.org/problems/queue-reversal/1
Approach1: Using stack
Time complexity: O(n) where n is the number of elements in the queue
Space complexity: O(n) for the stack

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
    }
};