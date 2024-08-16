#include<bits/stdc++.h>
using namespace std;

bool canplace(vector<int>& stalls,int k,int dist){
    int noofcow=1,last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last >=dist){
            noofcow++;
            last=stalls[i];
        }
        if(noofcow>=k)
        return true;
    }
    return false;
}
int aggressiveCowsBF(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int maxi=stalls[n-1]-stalls[0];
    for(int i=1;i<=maxi;i++){
        if(canplace(stalls,k,i))
           continue;
        else 
           return i-1;
    }
    return maxi;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int maxi=stalls[n-1]-stalls[0];
    int low=1,high=maxi;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canplace(stalls,k,mid))
          low=mid+1;
          else 
          high=mid-1;
    }
    return high;
}
int main(){
    vector<int> stalls{0, 3 ,4 ,7 ,10, 9};
    int k;
    cout<<"Enter the cows ";
    cin>>k;
    cout<<aggressiveCowsBF(stalls,k);
return 0;
}