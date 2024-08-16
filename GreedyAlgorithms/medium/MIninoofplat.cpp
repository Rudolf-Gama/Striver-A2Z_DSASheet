#include<bits/stdc++.h>
using namespace std;

int findPlatformOP(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0,cnt=0,maxcnt=0;
    	while(i<n){
    	    if(arr[i]<=dep[j])
    	    cnt++,i++;
    	    else
    	    cnt--,j++;
    	    maxcnt=max(cnt,maxcnt);
    	}
    	return maxcnt;
    }

int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int maxcnt=0;
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=0;j<n;j++){
                if( i!=j && dep[i]>arr[j] && dep[j]>arr[i])
                cnt++;
            }
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }

int main(){
    int arr[]= {900,940,950,1100, 1500,1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatformOP(arr,dep,6);
    return 0;
}