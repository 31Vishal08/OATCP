
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define mod 1000000007
// const int N = 1e7+10;
// ll hsh[N];

vector<string> briefWords(string &str, string s, int i, int n) {
    vector<string> res;
    if(n == 0) {
        res.push_back(s);
        return res;
    }
    if(i == str.length()) {
        return res;
    }
    vector<string> t = briefWords(str, s + str[i], i + 1, n - 1);
    res.insert(res.end(), t.begin(), t.end());
    vector<string> nt = briefWords(str, s, i + 1, n);
    res.insert(res.end(), nt.begin(), nt.end());
    return res;
}

int main() {
    freopen("ip.txt", "r", stdin);
    freopen("op1.txt", "w", stdout);
    
    int n;
    set<string> ss;
    cin >> n;

    vector<vector<string>> ans;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<string> temp;
        for(int i = 1; i <= 4; ++i) {
            vector<string> subs = briefWords(s, "", 0, i);
            for(int j = 0; j < subs.size(); j++) {
                if(ss.find(subs[j]) == ss.end()) {
                    temp.push_back(subs[j]);
                    ss.insert(subs[j]);
                }
            }
        }
        ans.push_back(temp);
    }
    cout<<"\nOutput:"<<endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << "\n";
        }
        cout << "\n" << "\n";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}