#include<bits/stdc++.h>
using namespace std;
 int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
            int cnt=0;
            for(int i=0;i<N;i++){
                int sum=0;
                for(int j=i;j<N;j++){
                    sum+=arr[j];
                    if(sum>target) break;
                    else if(sum==target) cnt++;
                }
            }
            return cnt;
    }

    int numberOfSubarraysOP1(vector<int>& arr, int N, int target){
        // code here
        int cntK=0;
        int cntmK=0;
        int sum=0,sum1=0;
        int r=0,l=0,l1=0;
        while(r<N){
            sum+=arr[r];
            sum1+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            while(sum1>target-1){
                sum1-=arr[l1];
                l1++;
            }
            if(sum<=target){
                cntK+=(r-l+1);
            }
            if(sum1<=target-1){
                cntmK+=(r-l1+1);
            }
            r++;
        }
        return (cntK-cntmK);
    }
  int countsubarray(vector<int>& arr, int N, int target){
        
        int cnt=0;
        int sum=0;
        int r=0,l=0;
        while(r<N){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            if(sum<=target){
                cnt+=(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarraysOP2(vector<int>& arr, int N, int target){
        // code here
        return (countsubarray(arr,N,target)-countsubarray(arr,N,target-1));
    }
    int main(){
        vector<int> arr{1,0,1,0,1};
        int target;
        cin>>target;
        cout<<numberOfSubarrays(arr,arr.size(),target);
        return 0;
    }