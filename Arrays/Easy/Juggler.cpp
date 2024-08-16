#include<bits/stdc++.h>
using namespace std;
 vector<long long> jugglerSequence(long long n) {
        vector<long long> ans;
        ans.push_back(n);
        long long temp=n;
        while(temp!=1){
            if(temp%2==0){
             temp=sqrt(temp);
            }
            else{
             temp=sqrt(temp)*sqrt(temp)*sqrt(temp);
            }
            ans.push_back(temp);
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
  vector<long long> ans=jugglerSequence(n);
  for(auto it: ans){
    cout<<it<<" ";
  }
    return 0;
}