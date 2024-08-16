#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappedIntervalBP(vector<vector<int>>& intervals){
         vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end());
         for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
             if(!ans.empty() && end <= ans.back()[1]) continue;
             for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<=end){
                    end=max(end,intervals[j][1]);
                }
                else{
                    break;
                }
             }
             ans.push_back({start,end});
         }
         return ans;
}

vector<vector<int>> overlappedIntervalOP(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end());
         for(int i=0;i<intervals.size();i++){
             if(ans.empty() || intervals[i][0] > ans.back()[1]){
                 ans.push_back(intervals[i]);
             }
             else {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
             }
         }
         return ans;
 }


int main()
{
	vector<vector<int>>Intervals{{6,8},{1,9},{2,4},{4,7}};
	vector<vector<int>> ans = overlappedIntervalBP(Intervals);
	for(auto i: ans){
		for(auto j: i){
			cout << j << " ";
		}
	}
	cout << "\n";
	return 0;
}
