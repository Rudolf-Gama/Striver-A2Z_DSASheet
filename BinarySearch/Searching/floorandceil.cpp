#include<bits/stdc++.h>
using namespace std;
 int ceil(vector<int> &a,int n,int x)	{
    int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
                if (a[mid] >= x) {
                  ans = a[mid];
                  high = mid - 1;
                } else
                  low = mid + 1;
        }
        return ans;
 }

int floor(vector<int> &a,int n,int x)	{
    int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
                if (a[mid] <= x) {
                  ans = a[mid];
                  low = mid + 1;
                } else
                  high = mid - 1;
        }
        return ans;
        }
		
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int c=ceil(a,  n,  x);
	int f=floor(a,  n, x);
       return { f,c };
}
int main(){
    vector<int> a{2,4,5,7,8,11,24,55};
    int x;
    cin>>x;
    pair<int, int> ans = getFloorAndCeil(a, a.size(), x);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}