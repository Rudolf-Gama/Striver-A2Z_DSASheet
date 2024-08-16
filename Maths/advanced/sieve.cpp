#include<bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int N) {
        vector<int> ans;
        vector<int> prime(N+1,1);
        for(int i=2;i*i<=N;i++){
            if(prime[i]==1)
            {
              for(int j=i*i;j<=N;j+=i)
              {
                  prime[j]=0;
              }
            }
        }
        
        for(int i=2;i<=N;i++){
            if(prime[i]==1)
            ans.push_back(i);
        }
        return ans;
    }

    int main(){
        int N;
        cin>>N;
        vector<int> ans=sieveOfEratosthenes(N);
        for(auto it:ans) cout<<it<<" ";
    } 