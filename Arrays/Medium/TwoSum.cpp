#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
           map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        int a=nums[i];
        int b=target-a;
        if(mpp.find(b)!=mpp.end()){
            return {mpp[b],i};
        }
        mpp[a]=i;
    }
    return {-1,-1};
    }

//true only for yes or no (2 pointer)
string readOP(int n, vector<int> book, int target)
{
  int left=0,right=n-1;
  sort(book.begin(),book.end());
 while(left<right){
     int sum=book[left]+book[right];
     if(sum==target) return "YES";
     else{
        if(sum>target) right--;
        else left++;
     }
 }
 return "NO";
}

int main(){
    vector<int> v{2,6,5,8,11};
    int target;
    cin>>target;
    vector<int> ans;
    ans=twoSum(v,target);
    for(auto it:ans)
    cout<<it<<" ";
    return 0;
}