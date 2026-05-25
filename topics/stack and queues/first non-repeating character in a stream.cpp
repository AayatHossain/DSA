https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

Approach: Using a queue
Time complexity: O(n) where n is the length of the string
Space complexity: O(n) for the queue in worst case when all characters are distinct.

class Solution {
  public:
    string firstNonRepeating(string &s) {
        int n = s.size();
        queue<int> q;
        string ans;
        vector<int> f(26,0);
        for(int i = 0; i < n; i++){
            int v = s[i] - 'a';
            f[v]++;
            if(f[v]==1)q.push(v);
            while(!q.empty() && f[q.front()] > 1){
                q.pop();
            }
            if(!q.empty()){
                ans+= char(q.front() + 'a');
            }else{
                ans+='#'
            }
        }
        return ans;
        
    }
};


Approach 2: Using frequency and first occurance array;
Time complexity: O(n*26) where n is the length of the string
Space complexity: O(26) for the frequency and first occurance array.

class Solution {
  public:
    string firstNonRepeating(string &s) {
        int n = s.size();
        vector<int> freq(26,0);
        vector<int> first(26,-1);
        string ans;
        for(int i = 0; i < n; i++){
            int v = s[i] - 'a';
            freq[v]++;
            if(freq[v] == 1){
                first[v] = i;
            }
            int idx = -1;
            int firstidx = n;
            for(int j = 0; j < 26; j++){
                if(freq[j] == 1 && first[j] < firstidx){
                    firstidx = first[j];
                    idx = j;
                }
            }
            if(idx != -1){
                ans += char(idx + 'a');
            }else{
                ans+='#';
            }
        }
        return ans;
    }
};