#include<bits/stdc++.h>
using namespace std;
vector<int> Intersection(vector<int>a,vector<int>b ){
int n1=a.size();
int n2=b.size();
vector<int> inter;
vector<int> visited(n2,0);
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        if(a[i]==b[j] && visited[j]==0){
            inter.push_back(a[i]);
             visited[j]=1;
             break;
        }
        if(b[j]>a[i]) break;  //condition only if sorted array or else dont write this works for unsorted as well
    }
}
return inter;
}

vector<int> IntersectionOP(vector<int>a,vector<int>b ){
int n1=a.size();
int n2=b.size();
vector<int> inter;
int i=0,j=0;
while(i<n1 && j<n2){
    if(a[i]<b[j]) i++;
    else if(a[i]>b[j]) j++;
    else{
        inter.push_back(a[i]);
        i++;j++;
    }
}
return inter;
}
int main(){
 vector<int> a{1,2,2,3,3,4,6};
    vector<int> b{1,2,2,4,6,7,8};
    vector<int> arr;
    arr=IntersectionOP(a,b);
    for(auto it: arr) cout<<it<<" ";
    return 0;
}