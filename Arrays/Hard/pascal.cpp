#include<bits/stdc++.h>
using namespace std;

 vector<int> generaterow(int row){
     long long ans=1;
     vector<int> line;
     line.push_back(ans);
     for(int i=1;i<row;i++){
         ans=ans*(row-i);
         ans=ans/i;
         line.push_back(ans);
     }
     return line;
 }
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) {
      ans.push_back(generaterow(i));
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the line of pascal triangle"<<endl;
    cin>>n;
    vector<vector<int>> final;
    final=pascalTriangle(n);
    for(auto it:final){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
   return 0;
}