class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n = s.size();
        int mid = (n+1)/2 ;
        int c = n;
        stack<int> temp;
        while( c >= mid){
            if(c == mid){
                s.pop();
                break;
            }
            temp.push(s.top());
            s.pop();
            c--;
        }
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return;
    }
};