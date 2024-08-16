#include<bits/stdc++.h>
using namespace std;
    // code here

    int canReach(int A[], int N) { int maxind=0;
        for(int i=0;i<N;i++){
            if(i>maxind) return 0;
            maxind=max(maxind,i+A[i]);
            if(i>=N) return 1;
        }
        return 1;
    }

int main(){
    int a[]={1, 2, 0, 3, 0, 0} ;
    int n=sizeof(a)/sizeof(a[0]);
    cout<<canReach(a,n);
    return 0;
}