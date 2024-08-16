#include<bits/stdc++.h>
using namespace std;
int isSorted(int n, vector<int> a) {
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]) return 0;
    }
    return 1;
}
int main(){
    vector<int> v{2,4,6,7,8,10};
    cout<<isSorted(v.size(),v);
    return 0; 
}