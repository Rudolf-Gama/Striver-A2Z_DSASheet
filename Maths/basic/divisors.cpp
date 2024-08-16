#include<bits/stdc++.h>
using namespace std;
//o(n)
void divisors(int n){
  for(int i=1;i<=n;i++){
    if(n%i==0){
        cout<<i<<" ";
    }
  }
}

//o()
void divisors1(int n){
    vector<int> v;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
       v.push_back(i);
       if((n/i)!=i)
       v.push_back(n/i);
    }
  }
  sort(v.begin(),v.end());
  for(auto it: v)cout<<it<<" ";
}
int main(){
    int n;
    cin>>n;
    // divisors(n);
    divisors1(n);
    return 0;
}