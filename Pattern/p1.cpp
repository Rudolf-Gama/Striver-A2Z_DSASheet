#include<bits/stdc++.h>
using namespace std;
/*
*****
*****
*****
*****
*****
*/
void patt1(int n){
 for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
*
**
***
****
*/
void patt2(int n){
 for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
1
12
123
1234
*/
void patt3(int n){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
}
/*
1
22
333
4444
*/
void patt4(int n){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
****
***
**
*
*/
void patt5(int n){
 for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){       //j=1;j<=n-i+1   i=1;i<=n
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
1234
123
12
1
*/
void patt6(int n){
 for(int i=n;i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
     *
    ***
   *****
  *******
*/
void patt7(int n){
 for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        
        cout<<endl; 
    }
}
/*
*******
 *****
  ***
   *
*/
void patt8(int n){
 for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl; 
    }
}
/*
     *
    ***
   *****
  *******
  *******
   *****
    ***
     *
*/
//combine both


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    int n;
    cout<<"Enter the number of lines"<<endl;
    cin>>n;
    //patt1(n);
   // patt2(n);
    //patt3(n);
    //patt4(n);
    //patt5(n);
   // patt6(n);   
   patt7(n);
   patt8(n);
  
    }
    return 0;
}