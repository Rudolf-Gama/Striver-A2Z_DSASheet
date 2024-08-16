#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        vector<vector<int>> ans;
        int i=0;
        while(i<N && intervals[i][1]< newEvent[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<N && intervals[i][0]<= newEvent[1]){
            newEvent[0]=min(intervals[i][0],newEvent[0]);
            newEvent[1]=max(intervals[i][1],newEvent[1]);
            i++;
        }
        ans.push_back(newEvent);
        while(i<N){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }

int main(){
    vector<vector<int>> intervals={{1,2},{3,4},{6,7},{8,10},{12,16}};
    vector<int> NewInterval{5,8};
    int N=intervals.size();
    vector<vector<int>> ans=insertNewEvent(N,intervals,NewInterval);
    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}