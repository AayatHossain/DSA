Approach1: Using Greedy Algorithm
Time complexity: O(n) where n is the number of gas stations
Space complexity: O(1) as we are using only constant extra space.

class Solution {
  public:
    int startStation(vector<int> &g, vector<int> &c) {
        //  code here
        int n = g.size();
        int curr = 0, start = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            curr += g[i] - c[i];
            if(curr < 0){
                start = i+1;
                curr = 0;
            }
            total += g[i] - c[i];
        }
        if(total >= 0)return start;
        return -1;
    }
};