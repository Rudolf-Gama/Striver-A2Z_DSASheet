#include<bits/stdc++.h>
using namespace std;
   int count(vector<vector<int>> &matrix, int R, int mid){
        int cnt=0;
        for(int i=0;i<R;i++){
            cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        int req=(R*C)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            int smallones=count(matrix,R,mid);
            if(smallones<=req)
              low=mid+1;
              else
              high=mid-1;
        }
        return low;
    }
int main(){
    vector<vector<int>> matrix{{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
    cout<<median(matrix,matrix.size(),matrix[0].size());
    return 0;
}