#include<bits/stdc++.h>
using namespace std;
vector<int> minPartition(int N)
    {
        // code here
        vector<int> deno{ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n=deno.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            while(deno[i]<=N){
                N-=deno[i];
                ans.push_back(deno[i]);
            }
            if(N==0)
            break;
        }
        return ans;
    }
int main(){
    int N;
    cin>>N;
    vector<int> ans=minPartition(N);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}