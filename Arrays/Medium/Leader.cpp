#include<bits/stdc++.h>
using namespace std;
vector<int> Leader(vector<int> &a){
    vector<int> ans;
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int flag=1;
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[n-1]);
    return ans;
}
vector<int> LeaderOP(vector<int> &a){
    vector<int> ans;
    int n=a.size();
    int maxi=a[n-1];
    ans.push_back(maxi);
    for(int i=n-2;i>=0;i--){
        if(a[i]>maxi){
            maxi=a[i];
            ans.push_back(a[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> a{17,16,13,15,3,6,1};
    vector<int> ans;
    ans=Leader(a);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}