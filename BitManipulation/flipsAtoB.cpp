#include<bits/stdc++.h>
using namespace std;
 int countBitsFlip(int a, int b){
        int ans=a^b;
        int cnt=0;
        while(ans>0){
            cnt+=ans&1;
            ans=ans>>1;
        }
        return cnt;
    }
int main(){
    int a,b;
    cin>>a>>b;
    cout<<countBitsFlip(a,b);
    return 0;
}