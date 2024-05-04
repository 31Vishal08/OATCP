#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define mod 1000000007
// const int N = 1e7+10;
// ll hsh[N];

int getsrc(unordered_map<int, pair<int, int>> &deg) {
    int src;
    for(auto it: deg) {
        auto itt = it.second;
        if(itt.second - itt.first == 1) {
            src = it.first;
            break;
        }
        src = it.first;
    }
    return src;
}

vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
{
    unordered_map<int, unordered_set<int>> graph;
    unordered_map<int, pair<int, int>> deg;
    for (auto p : pairs) {
        graph[p[0]].insert(p[1]);
        deg[p[1]].first++;  // indeg
        deg[p[0]].second++; // outdeg
    }
    int src = getsrc(deg);
    deque<int> path;
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top();
        if (graph[u].size() == 0) {
            path.push_front(u);
            st.pop();
        }
        else {
            int deg = *graph[u].begin();
            graph[u].erase(deg);
            st.push(deg);
        }
    }
    vector<vector<int>> ans;
    int n = path.size();
    for (int i = 0; i < n - 1; ++i) {
        ans.push_back({path[i], path[i + 1]});
    }
    return ans;
}

int main() {
    // freopen("sample_input2.txt", "r", stdin);
    // freopen("sample_output2.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> vp(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vp[i].push_back(x);
        vp[i].push_back(y);
    }

    vector<vector<int>> ans = validArrangement(vp);
    if (ans.size() != n) {
        cout << "No valid arrangement found!" << "\n";
    }
    else {
         cout << "Valid arrangement: " << "\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i][0] << " " << ans[i][1] << "\n";
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}