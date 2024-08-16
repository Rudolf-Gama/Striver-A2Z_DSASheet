#include<bits/stdc++.h>
using namespace std;
bool linear(vector<int> a,int num){
    for(int i=0;i<a.size();i++){
        if(a[i]==num)return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int longest=1;
    int n=a.size();
    for(int i=0;i<n;i++){
          int cnt=1;
          int x=a[i];
          while(linear(a,x+1)==true){
              x++;
              cnt++;
          }
      longest=max(longest,cnt);
    }
    return longest;
}


int longestSuccessiveElementsBP(vector<int>&a) {
    sort(a.begin(),a.end());
    int smallest=INT_MIN;
    int longest=1;
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
     if(a[i]-1==smallest){
         cnt++;
         smallest=a[i];
     }
     else if(a[i]!=smallest){
         cnt=1;
         smallest=a[i];
     }
     longest=max(longest,cnt);
    }
 return longest;
}


int longestSuccessiveElementsOP(vector<int>&a) {
   int n=a.size();
   int longest=1;
   unordered_set<int> st;
   for(int i=0;i<n;i++){
       st.insert(a[i]);
   }

    for(int i=0;i<n;i++){
        int x=a[i];
        int cnt=0;
        if(st.find(x-1)==st.end()){
               x++;
               cnt=1;
               while(st.find(x)!=st.end()){
                   cnt++;
                   x++;
               }
               longest=max(longest,cnt);
        }
    }
    return longest;
}


int main(){
    vector<int> a{5, 8, 3, 2, 1, 4,6};
    cout<<longestSuccessiveElementsOP(a);
    return 0;
}