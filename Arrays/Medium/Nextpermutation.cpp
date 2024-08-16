#include<bits/stdc++.h>
using namespace std;
vector<int> NextPermutation(vector<int>&a){
    int n=a.size();
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1) {
        reverse(a.begin(),a.end());
        return a;
    }
    for(int i=n-1;i>index;i--){
        if(a[i]>a[index]){
            swap(a[i],a[index]);
            break;
        }
    }
    reverse(a.begin()+index+1,a.end());
    return a;
}
int main(){
    vector<int> a{2,1,5,4,3,0,0};
    // next_permutation(a.begin(),a.end());
    // for(auto it:a) cout<<it<<" ";
    // cout<<endl;
    // cout<<"Using Intuation"<<endl;
    vector<int> ans;
    ans= NextPermutation(a);
    for(auto it:a) cout<<it<<" ";
    return 0;
}