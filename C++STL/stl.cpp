#include<bits/stdc++.h>
using namespace std;

int main(){
    // Pairs
    pair<int,int> p={1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int ,pair<int,float>> p1={3,{6,8}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;

    pair<int,int> p2[]={{1,3},{3,6}};
    cout<<p2[0].second;
    return 0;
}
