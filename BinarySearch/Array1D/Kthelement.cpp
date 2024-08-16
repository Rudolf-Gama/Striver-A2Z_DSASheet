#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
int kthElement(vector<int> &a, vector<int>& b, int n, int m, int k){

	if(n>m)  kthElement(b,a,m,n,k);

	int low=max(0,k-m),high=min(k,n);
    int left=k;
	while(low<=high){
		int mid=low+(high-low)/2;
		int mid2=left-mid;
		int l1=INT_MIN,l2=INT_MIN;
		int r1=INT_MAX,r2=INT_MAX;
		if(mid<n) r1=a[mid];
		if(mid2<m) r2=b[mid2];
		if(mid-1>=0) l1=a[mid-1];
		if(mid2-1>=0) l2=b[mid2-1];

		if(l1<=r2 && l2 <=r1)
		{
			 return max(l1,l2);
		
		}
		else if(l1>r2){
                high=mid-1;
		}
		else 
		low=mid+1;
	}
	return 0;
}
int main(){
    vector<int> a{2,4,6,7};
    vector<int> b{6,8,11,17};
    int k;
    cin>>k;
    cout<<kthElement(a,b,a.size(),b.size(),k);
    return 0;
}