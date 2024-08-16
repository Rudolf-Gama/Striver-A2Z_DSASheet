#include<bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr){
	int maxpro=INT_MIN;
	int n=arr.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int pro=1;
			for(int k=i;k<=j;k++){
                  pro=pro*arr[k];
				  maxpro=max(maxpro,pro);
			}
		}
	}
	return maxpro;
}

int subarrayWithMaxProductBP(vector<int> &arr){
	int maxpro=INT_MIN;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int pro=1;
		for(int j=i;j<n;j++){
                  pro=pro*arr[j];
				  maxpro=max(maxpro,pro);
		}
	}
	return maxpro;
}

int subarrayWithMaxProductOP(vector<int> &arr){
	int maxpro=INT_MIN;
	int n=arr.size();
	int pre=1,suf=1;
	for(int i=0;i<n;i++){
		if(pre==0) pre=1;
		if(suf==0) suf=1;
        pre*=arr[i];
		suf*=arr[n-1-i];
		maxpro=max(maxpro,max(pre,suf));
	}
	return maxpro;
}

int main(){
    vector<int> arr={6,-3,-10,0,2};
    cout<<subarrayWithMaxProductBP(arr)<<endl;
    return 0;
}