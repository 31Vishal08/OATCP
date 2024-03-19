// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
    long long f(vector<long long >& v) {
        long long n=v.size();
        long long mn = 1;
        long long mx = 1;
        long long ans = v[0];
        for(int i=0; i<n; i++){
            if(v[i] < 0){
                swap(mx, mn);
            }
            mx = max(mx*v[i], v[i]);
            mn = min(mn*v[i], v[i]);
            ans = (max(ans, mx))%mod;
        }
        return ans;
    }


int main() {
    // Write C++ code here
    int n;cin>>n;
    if(n==0) cout<<0<<endl;
    else {
        vector<long long >v;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        v.push_back(x);
    }
    cout<<f(v)<<endl;
    }
    return 0;
}