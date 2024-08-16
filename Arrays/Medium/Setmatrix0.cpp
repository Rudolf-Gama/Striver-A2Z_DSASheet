#include <bits/stdc++.h> 
using namespace std;
void rowcheck(vector<vector<int>> &matrix,int i,int m){
	for(int j=0;j<m;j++){
		if(matrix[i][j]!=0){
			matrix[i][j]=-1;
		}
	}
}
void colcheck(vector<vector<int>> &matrix,int j,int n){
	for(int i=0;i<n;i++){
		if(matrix[i][j]!=0){
			matrix[i][j]=-1;
		}
	}
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				rowcheck(matrix, i, m);
				colcheck(matrix, j,n);
			}
		}
	}
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(matrix[i][j]==-1){
			matrix[i][j]=0;
		}
	}
}
return matrix;
}

vector<vector<int>> zeroMatrixBP(vector<vector<int>> &matrix, int n, int m) {
	vector<int> row(n,0);
	vector<int> col(m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}

for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(row[i] || col[j]){
			matrix[i][j]=0;
		}
	}
}
return matrix;
}

vector<vector<int>> zeroMatrixOP(vector<vector<int>> &matrix, int n, int m) {
int col0=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				if(j!=0){
					matrix[0][j]=0;
				}
				else
				col0=0;
			}
		}
	}

for(int i=1;i<n;i++){
	for(int j=1;j<m;j++){
		if(matrix[i][0]==0 || matrix[0][j]==0){
			matrix[i][j]=0;
		}
	}
}
if(matrix[0][0]==0){
	for(int j=0;j<m;j++){
		matrix[0][j]=0;
	}
}
if(col0==0){
	for(int i=0;i<n;i++){
		matrix[i][0]=0;
	}
}
return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrixOP(matrix, n, m);
    cout << "The Final matrix is: "<<endl;
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
}