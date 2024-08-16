#include<bits/stdc++.h>
using namespace std;
long long divide(long long dividend, long long divisor) 
    {
        if(dividend == divisor) return 1;
        bool sign=true;
        if(dividend>=0 && divisor <0) sign=false;
        else if(dividend<0 && divisor>=0) sign =false;
        
        long long d=abs(divisor);
        long long n=abs(dividend);
        long long q=0;
        while(n>=d){
            int cnt=0;
              while(n>=(d<<(cnt+1)))
               cnt++;
            q+=(1<<cnt);
            n=n-(d*(1<<cnt));
        }
        if(q==(1<<31) && sign)
        return INT_MAX;
        else if(q==(1<<31) && !sign)
        return INT_MIN;
        
        return sign? q :-q;
    }
int main(){
    long long  n,d;
    cout<<"Enter the dividend and Divisor";
    cin>>n>>d;
    cout<<divide(n,d);
    return 0;
}