#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    //map 
    map<int,int> m;
    for(int i=0;i<n;i++) m[a[i]]++;

    //display how it stores in map
for(auto it: m) cout<<(it.first)<<"-->"<<(it.second)<<endl;

 // to find max and min
  int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
   
    for (auto it : m) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = element;
            minFreq = count;
        }
    }

    cout<<"Maximum element "<<maxEle<<endl;
    cout<<"Minimum element "<<minEle<<endl;
    // int q;
    // cin>>q;
    // while(q--){
    //     int num;
    //     cin>>num;
    //     cout<<"count of"<<num<<" is "<<m[num]<<endl;
    // }
    return 0; 
}