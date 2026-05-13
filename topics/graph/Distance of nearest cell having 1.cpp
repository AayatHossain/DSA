//multisource bfs, T = O(n*m), S = O(n*m)

class Solution {
  public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
  
    vector<vector<int>> nearest(vector<vector<int>>& g) {
        int n = g.size(); int m = g[0].size();
        vector<vector<int>> a(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j]==1){
                    q.push({i,j});
                    a[i][j] = 0;
                }    
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int ux = p.first;
            int uy = p.second;
            
            for(int i = 0; i < 4; i++){
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                
                bool valid = nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] > a[ux][uy]+1;
                if(valid){
                    a[nx][ny] = a[ux][uy]+1;
                    q.push({nx,ny});
                }
            }
        }
        return a;
        
    }
};