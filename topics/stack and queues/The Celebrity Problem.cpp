Approach: Using two pointers
Time complexity: O(n) where n is the number of people in the party
Space complexity: O(1) as we are using only constant extra space.

class Solution {
  public:
    int celebrity(vector<vector<int>>& m) {
        // code here
        int n = m.size();
        int i = 0, j = n-1;
        while(i < j){
            if(m[i][j] == 1){
                i++;
            }else{
                j--;
            }
        }
        if(i > j)return -1;
        for(int k = 0; k < n; k++){
            if(i==k)continue;
            if(m[i][k]==1 || m[k][i] == 0)return -1;
        }
        return i;
        
    }
};


Approach2: Using stack
Time complexity: O(n) where n is the number of people in the party
Space complexity: O(n) for the stack


class Solution {
  public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        stack<int> s;
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        while(s.size() >= 2){
            int p1 = s.top();
            s.pop();
            int p2 = s.top();
            s.pop();
            if(m[p1][p2]){
                s.push(p2);
            }else{
                s.push(p1);
            }
        }
        int p = s.top();
        for(int k = 0; k < n; k++){
            if(p==k)continue;
            if(m[p][k]==1 || m[k][p] == 0)return -1;
        }
        return p;
       
        
    }
};