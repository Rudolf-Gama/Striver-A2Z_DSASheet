#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
        // code here
        int top=0;
        int down=n-1;
        while(top<down){
            if(M[top][down]==1)
             top++;
             else if(M[down][top]==1)
             down--;
             else{
                 down--;
                 top++;
             }
        }
        if(top>down) return -1;
        for(int i=0;i<n;i++){
            if( i!=top && (M[top][i]==1 || M[i][top]==0))
            return -1;
        }
        return top;
    }

int celebrityST(vector<vector<int> >& M, int n) {
        // code here
        int top=0;
        int down=n-1;
        while(top<down){
            if(M[top][down]==1)
             top++;
             else if(M[down][top]==1)
             down--;
             else{
                 down--;
                 top++;
             }
        }
        if(top>down) return -1;
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if( (M[top][i]==0 && M[i][top]==1)){
                continue;
            }
            else
                return -1;
        }
        return top;
    }

    int main(){
        vector<vector<int>>M={{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
        cout<<celebrityST(M,4)<<endl;
    }