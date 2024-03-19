    // Online C++ compiler to run C++ program online
    #include <bits/stdc++.h>
    using namespace std;
    long long mod=1e9+7;
    int ff(vector<long long>& nums) {
        int sum =0;
        int f=0;
        for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			f+=i*nums[i];
		}
        
        int globalSum = f;
        
        for(int i=nums.size()-1;i>0;i--){
            f = f + sum -nums.size()*nums[i];
            globalSum = max(f,globalSum);
        }
        return globalSum;
    }

 
    int main() {
        // Write C++ code here
        int n;cin>>n;
        vector<long long >v;
        for(int i=0;i<n;i++){
            long long x;cin>>x;
            v.push_back(x);
        }
        cout<<ff(v)<<endl;
        return 0;
    }
    
