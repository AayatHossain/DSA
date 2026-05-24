
Approach 1: Using a stack.
Time complexity: O(n)
Space complexity: O(n) for the stack

class Solution {
public:
    bool validateOp(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        int j = 0;
        stack<int> s;
        for(int i = 0; i < n; i++){
            s.push(a[i]);
            
            while(!s.empty() && s.top() == b[j]){
                s.pop();
                j++;
            }
        }
        return j==m;
    }
};