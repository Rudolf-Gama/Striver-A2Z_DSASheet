#include<bits/stdc++.h>
using namespace std;
 long long power(int N,int R){
    long long ans = 1;
    long long n=N;
    int MOD = 1000000007;
    while (R > 0) {
        if (R & 1) {
            ans = (ans *n ) % MOD;
            R = R - 1;
        } else {
            n = (n*n) % MOD;
            R = R >> 1;
        }
    }
    return ans;
}
int main(){
    int L,R;
    cin>>L>>R;
    long long ans=power(L,R);
    cout<<ans;
    return 0;
}