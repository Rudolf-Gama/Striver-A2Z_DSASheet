#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &mat){
	 int n=mat.size();
	  int m=mat[0].size();
	  vector<vector<int>> ans(n,vector<int>(m));
	  for(int i=0;i<n;i++){
		  for(int j=0;j<m;j++){
			    ans[j][m-1-i]=mat[i][j];
		  }
	  }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         mat[i][j] = ans[i][j];
    //     }
    // }
    return ans;
}

void rotateMatrixOP(vector<vector<int>> &mat){
	// Write your code here.
	 int n=mat.size();
	 int m=mat[0].size();
     for(int i=0;i<n-1;i++){
		 for(int j=i+1;j<m;j++){
               swap(mat[i][j],mat[j][i]);
		 }
	 }
 
     for(int i=0;i<n;i++){
		 reverse(mat[i].begin(),mat[i].end());
	 }

}
int main(){
    vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
     for(auto it: mat){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // mat=rotateMatrix(mat);
    rotateMatrixOP(mat);
    for(auto it: mat){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}