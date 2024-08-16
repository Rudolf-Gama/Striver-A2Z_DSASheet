#include<bits/stdc++.h>
using namespace std;
int nCr(int r,int c){
    long long res=1;
    for(int i=1;i<=c;i++){// 0 to i<c
        // res=res*(r-i);
        // res=res/(i+1);
        res=res*(r-i+1);
        res=res/i;
    }
    return res;
}
int pascalelement(int row,int column){
   int element;
   element=nCr(row-1,column-1);
   return element;
}

 int main(){
    int r,c;
    cout<<"Enter the row"<<endl;
    cin>>r;
    cout<<"Enter the column"<<endl;
    cin>>c;
    cout<<"The element is ";
    cout<<pascalelement(r,c);
    return 0;
 }