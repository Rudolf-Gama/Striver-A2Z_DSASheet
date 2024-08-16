#include<bits/stdc++.h>
using namespace std;
 vector<int> findPrimeFactors(int N) {
        vector<int> ans;
        int prime[N+1];
        for(int i=1;i<=N;i++)
         prime[i]=i;
         
         for(int i=2;i*i<=N;i++){
            if(prime[i]==i){
                for(int j=i*i;j<=N;j+=i){
                    if(prime[j]==j)
                    prime[j]=i;
                }
            }
        }
        while(N!=1){
          ans.push_back(prime[N]);
          N=N/prime[N];
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
int main(){
    int N;
    cin>>N;
    vector<int> ans=findPrimeFactors(N);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}