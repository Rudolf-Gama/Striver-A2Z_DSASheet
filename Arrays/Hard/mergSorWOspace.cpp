#include<bits/stdc++.h>
using namespace std;
void swaparray(vector<long long> &a, vector<long long> &b,int n,int m){
	if(a[n]>b[m]){
		swap(a[n],b[m]);
	}
}
void mergeTwoSortedArraysWithoutExtraSpaceOP2(vector<long long> &a, vector<long long> &b){
	int n=a.size();
	int m=b.size();
    int len=n+m;
	int gap=(len/2)+(len%2);
	while(gap>0){
		int l=0;
		int r=gap;
		while(r<len){
			if(l<n && r>=n){
				swaparray(a, b, l,r-n);
			}
			else if(l<n && r<n){
				swaparray(a, b, l,r);
			}
			else{
				swaparray(a,b,l-n,r-n);
			}
            l++;
            r++;
		}
		if(gap==1) break;
	     gap=(gap/2)+(gap%2);
	}
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n=a.size();
	int m=b.size();
	int left=n-1;
	int right=0;
	while(left>=0 && right<m){
		if(a[left]>b[right]){
			swap(a[left],b[right]);
			left--;
			right++;
		}
        else {
	          break;
            }
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
}
int main(){
    vector<long long> a{1,2,5,7,8};
    vector<long long> b{3,6,9,11,15};
    mergeTwoSortedArraysWithoutExtraSpaceOP2(a,b);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:b){
        cout<<i<<" ";
    }
    return 0;
}