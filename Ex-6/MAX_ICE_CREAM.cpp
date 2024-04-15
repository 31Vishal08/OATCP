#include <bits/stdc++.h>
using namespace std;
#define int long long int


    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < costs.size(); i++)
        {
            pq.push(costs[i]);
        }
        int count = 0;
        while (coins > 0 && count != costs.size())
        {
            if (pq.top() > coins)
                break;
            coins -= pq.top();
            pq.pop();
            count++;
        }
        return count;
    }



void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int c;cin>>c;
    cout<<"O/P: "<<maxIceCream(v,c)<<endl;

    return;
}

signed main()  {solve();}