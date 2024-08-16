#include<bits/stdc++.h>
using namespace std;

vector<int> ncr(int n)
{
   vector<int> row;
   long long res=1;
   row.push_back(res);
   for(int i=1;i<n;i++)
   {
    res=res*(n-i);
    res=res/i;
    row.push_back(res);
   }
return row;
}

int main(){
    int n;
    cout<<"Enter the row"<<endl;
    cin>>n;
    vector<int> ans;
    ans=ncr(n);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}