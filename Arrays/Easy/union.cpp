#include<bits/stdc++.h>
using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    
    int n1=a.size();
    int n2=b.size();

    set<int> st;
    for (int i = 0; i < n1; i++) {
      st.insert(a[i]);
    }
    for (int i = 0; i < n2; i++) {
      st.insert(b[i]);
    }

   vector<int> temp;
   for(auto it: st) {
       temp.push_back(it);
   }
   return temp;
}
vector<int> sortedArrayOP(vector<int> a, vector<int> b) {
  int n1 = a.size();
  int n2 = b.size();
  vector<int> result;
  int i=0,j=0;
  while(i<n1 && j<n2){
      if(a[i]<=b[j]){
          if(result.size()==0 || result.back()!=a[i]){
              result.push_back(a[i]);
          }
          i++;
      }
      else{
            if(result.size()==0 || result.back()!=b[j]){
              result.push_back(b[j]);
          }
          j++;
      }
  }
  while(i<n1){
       if(result.size()==0 || result.back()!=a[i]){
              result.push_back(a[i]);
          }
          i++;
  }
  while(j<n2){
       if(result.size()==0 || result.back()!=b[j]){
              result.push_back(b[j]);
          }
          j++;
  }
  return result;
}

int main(){
    vector<int> a{1,2,3,3,4};
    vector<int> b{4,4,5,6,7,8};
    vector<int> arr;
    arr=sortedArrayOP(a,b);
    for(auto it: arr) cout<<it<<" ";
    return 0;
}