#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    int low=1,high=n;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(((long long)mid*mid)<=n)
         low=mid+1;
         else 
         high=mid-1;
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    cout<<floorSqrt(n);
    return 0;
}