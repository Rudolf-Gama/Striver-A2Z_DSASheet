#include<bits/stdc++.h>
using namespace std;

 int subarrayCountbF(vector<int> &arr, int N, int k) {
        // code here
         int cnt=0;
        for(int i=0;i<N;i++){
            unordered_map<int,int>mpp;
            for(int j=i;j<N;j++){
                mpp[arr[j]]++;
                if(mpp.size()==k) cnt++;
                else if(mpp.size()>k) break;
            }
        }
        return cnt;
    }

int cntsub(vector<int> &arr, int N, int k){
        int l=0,r=0,cnt=0;
        unordered_map<int,int> mpp;
        while(r<N){
            mpp[arr[r]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return cntsub(arr,N,k)-cntsub(arr,N,k-1);
    }
    int main(){
        vector<int> arr{1, 2, 1, 2, 3};
        int k;
        cin>>k;
        cout<<subarrayCount(arr,arr.size(),k);
    }