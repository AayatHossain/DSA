class Solution {
public:
    int f(vector<int>& a, int k,int target, int start ){
        int cnt = 0;
        for(int i = start; i < a.size(); i+=2){
            cnt += min(abs(a[i] - target), k - abs(a[i] - target));
        }
        return cnt;
    }


    int minOperations(vector<int>& a, int k) {
        for(int i = 0; i < a.size(); i++){
            a[i] = a[i]%k;
        }
        int n = a.size();
        int oddk = 0;
        int mxcount1 = INT_MAX;
        for(int i = 0; i < k; i++){
            int cnt= 0;
            cnt = f(a, k, i, 1);
            if(cnt < mxcount1){
                mxcount1 = cnt;
                oddk = i;
            }

        }


        int evenk = 0;
        int mxcount2 = INT_MAX;
        for(int i = 0; i < k; i++){
            int cnt = 0;
            cnt = f(a, k, i, 0);
            if(cnt < mxcount2){
                mxcount2 = cnt;
                evenk = i;
            }

        }

        int ans = 0;
        if(oddk == evenk){
            int mn = INT_MAX;
            int v1 = oddk, v2 = evenk+1;
            if(v2>=k)v2 = 0;
            if(v1 != v2){
                mn = min(mn, mxcount1 + f(a, k, v2, 0));
            }
            v1 = oddk, v2 = evenk-1;
                if(v2<0)v2 = k-1;
            if(v1 != v2){
                mn = min(mn, mxcount1 + f(a, k, v2, 0));
            }
             v1 = oddk+1, v2 = evenk;
                if(v1>=k)v1 = 0;
            if(v1 != v2){
                mn = min(mn, mxcount2 + f(a, k, v1, 1));
            }
                v1 = oddk-1, v2 = evenk;
                if(v1<0)v1 = k-1;
            if(v1 != v2){
                mn = min(mn, mxcount2 + f(a, k, v1, 1));
            }
            ans = mn;
        }else{
            ans = mxcount1 + mxcount2;
        }

        // cout<<oddk<<" "<<evenk<<" "<<mxcount1<<" "<<mxcount2<<" "<<oi<<" "<<ei<<endl;   
        return ans;

    }
};©leetcode