#include<bits/stdc++.h>
using namespace std;
double median(vector<int>& a, vector<int>& b) {
	int n=a.size();
	int m=b.size();
	vector<int> ans;
	int i=0,j=0;
	while(i<n && j<m){
		if(a[i]<b[j])
		{
			ans.push_back(a[i]);
			i++;
		}
		else{
			ans.push_back(b[j]);
			j++;
		}
	}
	while(i<n){
			ans.push_back(a[i]);
			i++;
	}
	while(j<m){
			ans.push_back(b[j]);
			j++;
	}
	int s=n+m;
   if(s%2==1)
   return (double) ans[s/2];
   else{
	   double d=(double)(ans[s/2]+ans[(s/2)-1]);
	 return (double) d/2.0;
   }
}

double medianBP(vector<int>& a, vector<int>& b) {
	int n=a.size();
	int m=b.size();
	int t=n+m;
	int ind2=t/2;
	int ind1=ind2-1;
	int e1=-1,e2=-1;
	int i=0,j=0;
	int cnt=0;
	while(i<n && j<m){
		if(a[i]<b[j])
		{
			if(cnt==ind1) e1=a[i];
			if(cnt==ind2) e2=a[i];
             cnt++;
			 i++;
		}
		else{
			if(cnt==ind1) e1=b[j];
			if(cnt==ind2) e2=b[j];
             cnt++;
			j++;
		}
	}
	while(i<n){
			if(cnt==ind1) e1=a[i];
			if(cnt==ind2) e2=a[i];
             cnt++;
			 i++;
	}
	while(j<m){
			if(cnt==ind1) e1=b[j];
			if(cnt==ind2) e2=b[j];
             cnt++;
			j++;
	}

   if(t%2==1)
   return (double) e2;
   else{
	   double d=(double)(e1+e2);
	 return (double) d/2.0;
   }
}

double medianOP(vector<int>& a, vector<int>& b) {
	int n=a.size();
	int m=b.size();
	if(n>m) median(b,a);
    int left=(n+m+1)/2;
	int low=0,high=n;
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
			if((n+m)%2==1)
			 return max(l1,l2);
			 else 
			 return (double)(max(l1,l2)+min(r1,r2))/2.0;
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
    vector<int> n{1,4,6,8};
    vector<int> m{2,3,7};
    cout<<medianBP(n,m);
    return 0;
}