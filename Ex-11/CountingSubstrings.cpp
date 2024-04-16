#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>color, int n) {
    int subgrids = 0;
    for(int a = 0; a < n; a++) {
        for(int b = a+1; b < n; b++) { // loop over pairs(a,b)of rows
            int count = 0;
            for(int i = 0; i < n; i++) { // loop over all columns
                if (color[a][i] == 1 && color[b][i] == 1) {
                    count++;
                }
            }
            subgrids += ((count-1) * count)/2;
        }
    }
    return subgrids;
}


int main(){
    int n;cin>>n;
    vector<vector<int>>c (n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin>>c[i][j];
    }
    // string c;cin>>c;
    //  int cc;cin>>cc;
    cout<<"output : "<<f(c,n);
}