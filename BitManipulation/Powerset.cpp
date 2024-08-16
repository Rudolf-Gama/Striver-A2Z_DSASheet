#include<bits/stdc++.h>
using namespace std;
	vector<string> AllPossibleStrings(string s){
		    int n=s.length();
		    vector<string> ans;
		    for(int i=1;i<(1<<n);i++){
		        string str="";
		        for(int j=0;j<n;j++){
		            if(i&(1<<j))
		              str.push_back(s[j]);
		        }
		        ans.push_back(str);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}

	vector<vector<int>> AllPossiblesubset(vector<int> num){
		    int n=num.size();
		    vector<vector<int>> ans;
		    for(int i=0;i<(1<<n);i++){
		        vector<int> list;
		        for(int j=0;j<n;j++){
		            if(i&(1<<j))
		              list.push_back(num[j]);
		        }
		        ans.push_back(list);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
int main(){
    // string s;
    // cin>>s;
    // vector<string> str=AllPossibleStrings(s);
    // for(auto it: str) cout<<it<<" ";
    vector<int> num{1,2,3};
    vector<vector<int>> ans=AllPossiblesubset(num);
    for(auto it: ans){
        for(auto i:it)
        cout<<i;
      cout<<" ";
    }
    return 0;
}