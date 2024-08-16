#include<bits/stdc++.h>
using namespace std;
int maxones(vector<int>&a,int n){
    int max=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==1) cnt++;
        else cnt=0;
        if(max<cnt)max=cnt;
    }
    return max;
}
int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==1){
                cnt++;
                maxi=max(cnt,maxi);
             }
             else cnt=0;
        }  
        return maxi; 
        }
int main(){
    vector<int> a{0,0,0,0};
    int n=a.size();
    int i=maxones(a,n);
    cout<<i;
}