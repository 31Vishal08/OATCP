#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n;
        bool grid[n+1][n+1];
 
        //Input, hai na cool xD
 
        rep(i,1,n+1)rep(j,1,n+1){
            char ch;cin >> ch;
            if(ch == '.')grid[i][j] = 0;
            else grid[i][j] = 1;
        }
 
        int dp[n+1][n+1];
        for(int i = n; i >= 1; i--)
        {
            for(int j = n; j >= 1; j--)
            {
                if(i == n && j == n)
                    dp[i][j] = 1;
                else
                {
                    int op1 = (j == n) ? 0 : dp[i][j+1];
                    int op2 = (i == n) ? 0 : dp[i+1][j];
                    dp[i][j] = (op1 + op2) % mod;
                    if(grid[i][j])
                        dp[i][j] = 0;
                }
            }
        }
        if(grid[n][n])
            cout << 0;
        else cout <<"output "<< dp[1][1];
   }
   return 0;
}