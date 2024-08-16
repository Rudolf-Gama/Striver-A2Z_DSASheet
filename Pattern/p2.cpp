#include<bits/stdc++.h>
using namespace std;
/*

*
**
***
**
*

*/

void patt1(int n){
    for(int i=0;i<2*n-1;i++){
       int star=i;
       if(star>=n) star=2*n-i-2;
       for(int j=0;j<=star;j++){
        cout<<"*";
       }
       cout<<endl;
    } 
}

void patt1b(int n){
    for(int i=1;i<=2*n-1;i++){
       int star=i;
       if(star>=n) star=2*n-i;
       for(int j=1;j<=star;j++){
        cout<<"*";
       }
       cout<<endl;
    } 
}

/*
1
01
101
0101
*/

void patt11(int n){
    int start=1;
    for(int i=0;i<n;i++){
       if(i%2==0) start=1;
       else start=0;
       for(int j=0;j<=i;j++){
        cout<<start<<" ";
           start=1-start;
       }
       cout<<endl;
    } 
}
/*
1      1
12    21
123  321
12344321
*/
void patt12(int n){
    for(int i=1;i<=n;i++){
       for(int j=1;j<=i;j++){
        cout<<j;
       }
       for(int j=1;j<=((2*n)-(2*i));j++){
        cout<<" ";
       }
       for(int j=i;j>0;j--){
        cout<<j;
       }
       cout<<endl;
    } 
}
/*
1
2 3
4 5 6
7 8 9 10 
11 12 13 14 15
*/
void patt13(int n){
       int star=1;
    for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++){
        cout<<star++<<" ";
       }
       cout<<endl;
    } 
}
/*
A
A B
A B C
A B C D
A B C D E
*/
void patt14(int n){
    for(int i=0;i<n;i++){
       char a='A';
       for(int j=0;j<=i;j++){
        cout<<a++<<" ";
       }
       cout<<endl;
    } 
}
/*
A B C D 
A B C 
A B 
A 
*/
void patt15(int n){
    for(int i=0;i<n;i++){
       for(char ch='A';ch<=('A'+(n-i-1));ch++){
        cout<<ch<<" ";
       }
       cout<<endl;
    } 
}
/*
A
B B
C C C
D D D D
*/
void patt16(int n){
       char a='A';
    for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++){
        cout<<a<<" ";
       }a++;
       cout<<endl;
    } 
}
void patt16b(int n){
    for(int i=0;i<n;i++){
        char ch='A'+i;
       for(int j=0;j<=i;j++){
        cout<<ch<<" ";
       }
       cout<<endl;
    } 
}
/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
void patt17(int n){
 for(int i=0;i<n;i++){
    char ch='A';
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<ch;
            if(j>=((2*i+1)/2)) ch--;
            else ch++;
        }
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl; 
    }
}
/*
E
D E
C D E
B C D E
A B C D E
*/
void patt18(int n){
    for(int i=0;i<n;i++){
       char start='A'+(n-i-1);
       for(int j=0;j<=i;j++){
        cout<<start++<<" ";
       }
       cout<<endl;
    } 
}
/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
void patt19(int n){
    int spac=0;
    for(int i=0;i<n;i++){
    for(int k=0;k<n-i;k++)
    {
        cout<<"*";
    }
    for(int k=0;k<spac;k++)
    {
        cout<<" ";
    }
    for(int k=0;k<n-i;k++)
    {
        cout<<"*";
    }
    spac+=2;
    cout<<endl;
    }
    spac=8;
    for(int i=0;i<n;i++){
    for(int k=0;k<i+1;k++)
    {
        cout<<"*";
    }
    for(int k=0;k<spac;k++)
    {
        cout<<" ";
    }
    for(int k=0;k<i+1;k++)
    {
        cout<<"*";
    }
    spac-=2;
    cout<<endl;
    }
}
void patt19b(int n){
   
    for(int i=0;i<n;i++){
    for(int k=0;k<n-i;k++)
    {
        cout<<"*";
    }
    for(int k=0;k<2*i;k++)
    {
        cout<<" ";
    }
    for(int k=0;k<n-i;k++)
    {
        cout<<"*";
    }
    cout<<endl;
    }
    for(int i=0;i<n;i++){
    for(int k=0;k<i+1;k++)
    {
        cout<<"*";
    }
    for(int k=0;k<((2*n)-(2*i)-2);k++)
    {
        cout<<" ";
    }
    for(int k=0;k<i+1;k++)
    {
        cout<<"*";
    }
    cout<<endl;
    }
}
/*
*    *
**  **
******
**  **
*    *
*/
void patt20(int n){
    for(int i=1;i<=2*n-1;i++){
        int row=i;
        if(row>n) row=2*n-i;
    for(int k=1;k<=row;k++)
    {
        cout<<"*";
    }
    for(int k=1;k<=((2*n)-(2*row));k++)
    {
        cout<<" ";
    }
    for(int k=1;k<=row;k++)
    {
        cout<<"*";
    }
    cout<<endl;
    }
}

/* 
****
*  *
*  *
****
*/
void patt21(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1||j==1||i==n||j==n)
             cout<<"*";
             else cout<<" ";
        }
       cout<<endl;
    }
}
/*
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/
void patt22(int n)
{
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i,left=j,down=2*n-2-i,right=2*n-2-j;
            cout<<n-min(min(top,down),min(left,right));
        }cout<<endl;
    }
  }
    
int main(){
int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    int n;
    cout<<"Enter the number of lines"<<endl;
    cin>>n;
   // patt1b(n);
   // patt11(n);
   // patt12(n);
    // patt13(n);
   //patt14(n);
    //patt15(n);
   // patt16(n);
    // patt16b(n);
    //  patt17(n);
    // patt18(n);
    // patt19(n);
    //  patt19b(n);
    // patt20(n);
    //  patt21(n);
     patt22(n);
    }
    return 0;
}