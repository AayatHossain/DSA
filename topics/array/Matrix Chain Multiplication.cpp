#include<bits/stdc++.h>
using namespace std;
signed main(){
    int size; cin>>size;
    vector<int> a(size);
    for(int i=0; i<size; i++) cin>>a[i];

    int n = size-1;
    vector<vector<int>> m(n+1, vector<int>(n+1,-1));
    vector<vector<int>> s(n+1, vector<int>(n+1,-1));

    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for(int chainlen = 2; chainlen <= n; chainlen++){
        for(int i = 1; i + chainlen - 1 <= n; i++){
            int j = i + chainlen - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int cost = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];
                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}