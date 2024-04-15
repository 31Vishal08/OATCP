#include <bits/stdc++.h>
using namespace std;
#define int long long int


        static bool cmp(string& a,string& b)
        {
            return a+b>b+a;
        }
        
        string largestNumber(vector<int>& nums) {
            vector<string>v;
            int flag=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0)
                    flag=1;
                v.push_back(to_string(nums[i]));
            }
            if(flag==0)
                return "0";
            sort(v.begin(),v.end(),cmp);
            string ans="";
            for(int i=0;i<v.size();i++)
                ans+=v[i];
            return ans;
        }



void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<"output : "<<largestNumber(v)<<endl;

    return;
}

signed main()  {solve();}