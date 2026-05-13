stack approach. T = O(n) S = O(n)

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& a) {
        //  code here
        int n =  a.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && a[i] <= s.top()){
                s.pop();
            }
            
            if(s.empty()){
                res[i] = -1;
            }else{
                res[i] = s.top();
            }
            s.push(a[i]);
        }
        return res;
        
    }
};