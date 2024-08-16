#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int maxone=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt+=matrix[i][j];
        }
        if(cnt>maxone){
            maxone=cnt;
            index=i;
        }
    }
    return index;
}
int lowerbound(vector<int>a,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else 
        low=mid+1;
    }
    return ans;
}
int rowWithMax1sOP(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int maxone=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cntone=m-lowerbound(matrix[i],m,1);
        if(cntone>maxone){
            maxone=cntone;
            index=i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> matrix{{0,0,1,1,1},{0,1,1,1,1},{1,1,1,1,1}};
    int n=matrix.size();
    int m=matrix[0].size();
    cout<<rowWithMax1sOP(matrix,n,m);
    return 0;
}