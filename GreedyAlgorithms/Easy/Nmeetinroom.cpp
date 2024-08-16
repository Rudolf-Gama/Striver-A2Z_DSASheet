#include<bits/stdc++.h>
using namespace std;
struct Data{
        int start;
        int end;
        int pos;
    }; 
     static bool comp(Data a,Data b){
         return a.end<b.end;
     }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        Data arr[n];
        for(int i=0;i<n;i++){
            arr[i].start=start[i];
            arr[i].end=end[i];
            arr[i].pos=i+1;
        }
        sort(arr,arr+n,comp);
        int cnt=1,freetime=arr[0].end;
        for(int i=1;i<n;i++){
            if(arr[i].start>freetime){
                cnt++;
                freetime=arr[i].end;
            }
        }
        return cnt;
    }

struct Data1{
        int S;
        int F;
        int P;
    };
    static bool comp1(Data1 a,Data1 b){
        return a.F<b.F;
    }
    vector<int> maxMeetingsMed(int N,int S[],int F[]){
        Data1 arr[N];
        for(int i=0;i<N;i++){
            arr[i].S=S[i];
            arr[i].F=F[i];
            arr[i].P=i+1;
        }
        sort(arr,arr+N,comp1);
        int cnt=1,freetime=arr[0].F;
        vector<int> ans;
        ans.push_back(arr[0].P);
        
        for(int i=1;i<N;i++){
            if(arr[i].S>freetime){
                cnt++;
                ans.push_back(arr[i].P);
                freetime=arr[i].F;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    int main(){
        int start[]={0,3,1,5,5,8};
        int end[]={5,4,2,9,7,9};
        int n=sizeof(start)/sizeof(start[0]);
        cout<<maxMeetings(start,end,n)<<endl;
        vector<int> ans=maxMeetingsMed(n,start,end);
        for(auto it: ans){
            cout<<it<<" ";
        }
        return 0;
    }
