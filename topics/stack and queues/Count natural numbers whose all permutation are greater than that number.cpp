    Approach: Using bfs.
    Time complexity: O(K)
    Space complexity: O(K) where K is the amount of numbers generated.
    
    #include <bits/stdc++.h>
    using namespace std;
    signed main()
    {
        int n;
        cin >> n;
        int cnt = 0;
        queue<int> q;
        for (int i = 1; i <= 9 && i <= n; i++)
        {
            q.push(i);
            cnt++;
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int i = v%10; i<=9; i++ ){
                int newv = v*10 + i;
                if(newv <= n){
                    cnt++;
                    q.push(newv);
                }
            }
        }
        cout<<cnt<<endl;

        return 0;
    }