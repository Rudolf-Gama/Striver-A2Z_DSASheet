#include<bits/stdc++.h>
using namespace std;
int subarraysWithSumKOP(vector < int > a, int b) {
    int n=a.size();
    unordered_map<int,int> mpp;
    int xorr=0;
    mpp[xorr]++;
    int cnt=0;
    for(int i=0;i<n;i++){
        xorr=xorr^a[i];
        int x=xorr^b;
        cnt+=mpp[x];
        mpp[xorr]+=1;
    }
    return cnt;
}


int subarraysWithSumKBP(vector < int > a, int b) {
    int n=a.size();
    int cnt=0;
   for(int i=0;i<n;i++){
       int xorr=0;
       for(int j=i;j<n;j++){
           xorr=xorr^a[j];
           if(xorr==b) cnt++;
       }
   }
   return cnt;
}
int subarraysWithSumK(vector < int > a, int b) {
        int n=a.size(); 
    int cnt=0;
   for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
             int xorr=0;
           for(int k=i;k<=j;k++)
               xorr^=a[k];
           if(xorr==b) cnt++;
       }
   }
   return cnt;
}
int main(){
    vector<int> arr{1 ,3, 3, 3, 5 };
    int k;
    cin>>k;
    cout<<subarraysWithSumKOP(arr,k);
    return 0;
}