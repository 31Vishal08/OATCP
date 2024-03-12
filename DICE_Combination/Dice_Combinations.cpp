#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define dbl double
#define print(x) cout<<x<<endl
#define vect(type1, name) vector<type1> name
#define vectp(type1, type2, name) vector<pair<type1, type2>> name
#define set(type, name) set<type> name
#define mpp(type1, type2, name) map<type1, type2> name
#define pb push_back
#define fir first
#define sec second
#define full(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626
#define vin() for(ll i=0;i<n;i++) cin>>v[i]
#define vout() for(ll i=0;i<n;i++) cout<<v[i]
#define loop(i,a,b) for(ll i=a;i<b;i++)
ll power(ll a, ll b)
{
    ll res = 1;
    for (ll i = 1; i <= b; i++)
        res *= a;
    return res;
}
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
ll isprime(ll x){
for (ll i = 2; i <= sqrtl(x); i++)
{
/* code */
if(x%i==0) return false;
}
return true;
}
void Sieve(ll n,vector<ll>&v)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            v.pb(p);
}
ll isPalindrome(string S){
string P = S;
reverse(P.begin(), P.end());
if (S == P)  return true;
else  return false;
}
void primeFactors(ll n,vector<ll>&v)
{
    while (n % 2 == 0)
    {
        // cout << 2 << " ";
        v.pb(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            // cout << i << " ";
            v.pb(i);
            n = n/i;
        }
    }
    if (n > 2)
        // cout << n << " ";
        v.pb(n);
}
ll fact(ll n) {
   if ((n==0)||(n==1))
   return 1;
   else
   return n*fact(n-1);
}
ll dp[1000005];
ll func(ll am,vector<ll>&v){
    if(am==0)return 1;
    if(dp[am]!=-1) return dp[am];
    ll c=0;
    loop(i,0,6){
        if(am-v[i]>=0) c=(c%1000000007+func(am-v[i],v)%1000000007)%1000000007;
    }
    return dp[am]=c;
}
void solve()
{
    ll am;
    cin >>am;
    vect(ll,v);
    loop(i,1,7){
        v.pb(i);
    }
    memset(dp,-1,sizeof(dp));
    print((func(am,v))%1000000007);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*#ifndef ONLINE_JUDGE
             freopen("in.txt", "r", stdin);
             freopen("output.txt", "w", stdout);
    #endif*/
    ll T = 1;
    // cin >> T;

    for (ll i = 1; i <= T; i++)
    {
       // cout << "Case #" << i << ": ";
        solve();
    }
}