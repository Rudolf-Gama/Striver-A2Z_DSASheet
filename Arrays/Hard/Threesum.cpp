#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
   set<vector<int>>   st;
   vector<vector<int>> ans;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           for(int k=j+1;k<n;k++)
           {
               if(arr[i]+arr[j]+arr[k]==0){
                   vector<int> temp={arr[i],arr[j],arr[k]};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
               }
           }
       }
   }
  for(auto it: st){
      ans.push_back(it);
  }
// vector<vector<int>> ans(st.begin(), st.end());

//   copy(st.begin(), st.end(), back_inserter(ans));
   return ans;

}

vector<vector<int>> tripletBP(int n, vector<int> &arr)
{
   set<vector<int>>   st;
   for(int i=0;i<n;i++){
       set<int> hash;
       for(int j=i+1;j<n;j++){
           int third=-(arr[i]+arr[j]);
               if(hash.find(third)!=hash.end())
               {
                   vector<int> temp={arr[i],arr[j],third};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
               }
           hash.insert(arr[j]);
       }
   }
vector<vector<int>> ans(st.begin(), st.end());
   return ans;
}


vector<vector<int>> tripletOP(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        int j=i+1,k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0) k--;
            else if(sum<0) j++;
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j-1]==arr[j]) j++;
                while(j<k && arr[k+1]==arr[k]) k--;
            }
        }
    }
    return ans;
}


int main(){
    vector<int> arr={-1, -1, 2, 0, 1};
    vector<vector<int>> ans;
    ans=tripletBP(arr.size(),arr);
    for(auto it :ans){
        for(auto it1: it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
