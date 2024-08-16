#include<bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int>&a) {
    int n=a.size();
    vector<int> ans(n);
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            neg.push_back(a[i]);
        }
        else {
            pos.push_back(a[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        ans[2*i]=pos[i];
        ans[2*i+1]=neg[i];
    }
    return ans;
}


vector<int> alternateNumbersOP(vector<int>&a) {
    int n=a.size();
    vector<int> ans(n,0);
    int pos=0,neg=1;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            ans[neg]=a[i];
            neg+=2;
        }
        else {
            ans[pos]=a[i];
            pos+=2;
        }
    }
    return ans;
}

  vector<int> RearrangebySign(vector<int>A, int n)
  {
  vector<int> pos;
  vector<int> neg;
  for(int i=0;i<n;i++){
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  if(pos.size() < neg.size()){
    for(int i=0;i<pos.size();i++){
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  else{
      for(int i=0;i<neg.size();i++)
      {
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
       }
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
}

void rearrange(int arr[], int n) {
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0) {
            pos.push_back(arr[i]);
        }
        else {
            neg.push_back(arr[i]);
        }
    }
    int i = 0, j = 0, k = 0;
    while (i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (i < pos.size()) {
        arr[k++] = pos[i++];
    }
    while (j < neg.size()) {
        arr[k++] = neg[j++];
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}

int main(){
vector<int> a{1 ,6 ,-3 ,-1, -2, 3,5,4,-3,2,-1,-1};
vector<int> ans;
ans=alternateNumbers(a);
for(auto it: ans){
    cout<<it<<" ";
}


//   vector<int> A {1,2,-4,-5,3,4};
//   vector<int> ans = RearrangebySign(A,A.size());
//   for (int i = 0; i < ans.size(); i++) {
//     cout << ans[i] << " ";
//   }

// int arr[]={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
// int n=sizeof(arr)/sizeof(arr[0]);
// rearrange(arr,n);
return 0;
}