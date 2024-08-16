#include<bits/stdc++.h>
using namespace std;


vector<int> moveZeros(int n, vector<int> a) {
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0) temp.push_back(a[i]);
    }
    for(int i=0;i<temp.size();i++){
      a[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        a[i]=0;
    }
    return a;
}


vector<int> moveZerosOP(int n, vector<int> a) {
    int j=-1;
    for(int i=0;i<n;i++)
    {
      if (a[i] == 0) 
      {
        j = i;
        break;
      }
    }
    if(j==-1) return a;

    for(int i=j+1;i<n;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
 return a;
}

int main(){
    vector<int> v{2,3,5,0,2,7,0,5,0,7};
    v=moveZerosOP(v.size(),v);
    for(auto it: v )cout<<it<<" ";
}
