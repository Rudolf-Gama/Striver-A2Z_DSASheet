#include<bits/stdc++.h>
using namespace std;
int findmax(vector<vector<int>> g,int n,int col){
 int index=-1,maxele=-1;
 for(int i=0;i<n;i++){
     if(g[i][col]>maxele){
         maxele=g[i][col];
         index=i;
     }
 }
 return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    int n=g.size();
    int m=g[0].size();
    int low=0,high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=findmax(g,n,mid);
        int left=mid-1>=0 ? g[row][mid-1] :-1;
        int right=mid+1<m ? g[row][mid+1] :-1;
        if (g[row][mid] > left && g[row][mid] > right) {
         return {row,mid};
        }
        else if(g[row][mid]<left) high=mid-1;
        else
        low=mid+1;
    }
    return {-1,-1};
}
int main(){
    vector<vector<int>> g{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans=findPeakGrid(g);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}
