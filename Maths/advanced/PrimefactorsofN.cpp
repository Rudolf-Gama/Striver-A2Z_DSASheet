#include<bits/stdc++.h>
using namespace std;
	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
	    for(int i=2;i*i<=N;i++){
	        if(N%i==0){
	            ans.push_back(i);
	            while(N%i==0)
	             N=N/i;
	        }
	    }
	    if(N!=1) ans.push_back(N);
	    return ans;
	}
int main(){
    int n;
    cin>>n;
    vector<int> ans=AllPrimeFactors(n);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}