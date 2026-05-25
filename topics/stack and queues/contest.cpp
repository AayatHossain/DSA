#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        
        int mn = LLONG_MAX;
        int mx = LLONG_MIN;

        for(int i=0; i<n; i++){
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
 
        int diff = mx - mn;
        int v = diff/2;
        int mid = mn + v;

        int v1 = abs(mid - mn);
        int v2 = abs(mid - mx);

        cout<<max(v1, v2)<<endl;


    }
}