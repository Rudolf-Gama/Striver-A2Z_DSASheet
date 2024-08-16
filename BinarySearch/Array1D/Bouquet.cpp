#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> arr,int day, int k, int m){
   int cnt=0,noofbouquet=0;
   for(int i=0;i<arr.size();i++){
	   if(arr[i]<=day)
	    cnt++;
		else {
			noofbouquet+=(cnt/k);
			cnt=0;
		}
   }
   		noofbouquet+=(cnt/k);	   
		   if(noofbouquet>=m)
		   return true;
		   else return false;
}


int roseGardenOP(vector<int> arr, int k, int m)
{
	 long long value=(k*1LL )*(m*1LL);
	 if(value>arr.size()) return -1;

	 int mini=INT_MAX,maxi=INT_MIN;
	 for(int i=0;i<arr.size();i++)
	 {
		 mini=min(mini,arr[i]);
		 maxi=max(maxi,arr[i]);
	 }

	 int low =mini,high=maxi;
	 while(low<=high){
		 int mid=low+(high-low)/2;
           if(possible( arr,mid, k, m))
		    high=mid-1;
          else
		  low=mid+1;
	 }
	 return low;
	 }

int roseGarden(vector<int> arr, int k, int m)
{
	 long long value=(k*1LL )*(m*1LL);
	 if(value>arr.size()) return -1;

	 int mini=INT_MAX,maxi=INT_MIN;
	 for(int i=0;i<arr.size();i++)
	 {
		 mini=min(mini,arr[i]);
		 maxi=max(maxi,arr[i]);
	 }
	 for(int i=mini;i<=maxi;i++){
		 if(possible(arr,i,k,m))
           return i;
	 }
}

int main(){
    vector<int> arr{7,7,7,7,13,11,12,7};
    int k,m;
    cout<<"Enter adajacent k ";
    cin>>k;
    cout<<"Enter the min value of bouquets ";
    cin>>m;
    cout<<roseGarden(arr,k,m);
    return 0;
}