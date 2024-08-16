#include<bits/stdc++.h>
using namespace std;
int cal(int num){
        if(num%4==1) return 1;
        else if(num%4==2) return num+1;
        else if(num%4==3) return 0;
        else return num;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return cal(l-1)^cal(r);
    }
int main(){
    int l,r;
    cin>>l>>r;
    cout<<findXOR(l,r);
    return 0;
}