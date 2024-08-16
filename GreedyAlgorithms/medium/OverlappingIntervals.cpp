#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int> &arr1,vector<int> &arr2){
        return arr1[1]<arr2[1];
    }
    
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
      sort(intervals.begin(),intervals.end(),comp);
      int cnt=1,last=intervals[0][1];
      for(int i=1;i<N;i++){
          if(intervals[i][0]>=last){
              cnt++;
              last=intervals[i][1];
          }
      }
      return N-cnt;
    }

int main(){
    vector<vector<int>> intervals={{1,2},{2,3},{3,4},{1,3}};
    int N=intervals.size();
    cout<<minRemoval(N,intervals)<<endl;
    return 0;
}