#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n=a.size();
    vector<int> ans;
    int rep=-1,mis=-1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==i)
             cnt++;
        }
        if(cnt==2) rep=i;
        else if(cnt==0)  mis=i;
        if(rep!=-1 && mis!=-1)  break;
    }
     ans.push_back(rep);
     ans.push_back(mis);
    return ans;
}

vector<int> findMissingRepeatingNumbersBP(vector < int > a) {
    int n=a.size();
    vector<int> ans;
    int rep=-1,mis=-1;
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(hash[i]==0) mis=i;
        else if(hash[i]==2) rep=i;
    }

    ans.push_back(rep);
    ans.push_back(mis);
    return ans;
}

vector<int> findMissingRepeatingNumbersOP(vector < int > a) {
    long long n=a.size();
    long long s1=(n*(n+1))/2;
    long long s2=(n*(n+1)*((2*n)+1))/6;
    long long ss1=0,ss2=0;
    for(int i=0;i<n;i++){
         ss1+=(long long)a[i];
         ss2+=(long long)a[i]*(long long)a[i];
    }
    long long val1=ss1-s1;
    long long val2=ss2-s2;
    val2=val2/val1;
    long long x=(val1+val2)/2;
    long long y=x-val1;
    return {(int)x,(int)y};
}
int main(){
    vector<int> a{1,2,3,4,5,7,8,7};
    vector<int> ans=findMissingRepeatingNumbersOP(a);
    for (auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
