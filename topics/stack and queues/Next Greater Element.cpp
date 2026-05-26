 Approach1: Using stack
Time complexity: O(n) where n is the number of elements in the array
Space complexity: O(n) for the stack
 
 class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& a) {
        // code here
        int n = a.size();
        stack<int> s;
        vector<int> ans(n,-1);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && a[i] >= s.top()){
                s.pop();
            }
            if(s.empty()){
                s.push(a[i]);
                continue;
            }else{
                ans[i] = s.top();
                s.push(a[i]);
            }
        }
        return ans;
        
    }
};