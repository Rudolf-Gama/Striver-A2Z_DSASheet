#include<bits/stdc++.h>
using namespace std;
vector<int> searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return {i,j};
        }
    }
    return {-1,-1};
}

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return {-1};
}

 vector<int> searchMatrixBP(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int index=-1;
    for (int i = 0; i < n; i++) {
        index= binarySearch(matrix[i], target);
        if(index != -1)
         return {i,index};
    }
    return {-1,-1};
}

vector<int> searchMatrixOP(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row=0,col=m-1;
    while(row<n && col >=0){
        if(matrix[row][col]==target) return {row,col};
        else if(matrix[row][col]<target)  row++;
        else col--;
    }
    return {-1,-1};
}


int main(){
  vector<vector<int>> matrix={{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  int target;
  cin>>target;
  vector<int> ans=searchMatrixOP(matrix,target);
  for(auto it:ans) cout<<it<<" ";
  return 0;
}