#include<bits/stdc++.h>
using namespace std;
 vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        map<string,vector<string>> mpp;
        
        for(int i=0;i<string_list.size();i++){
            string temp=string_list[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(string_list[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

    int main(){
        vector<string> string_list = {"cat", "dog", "god", "tca"};
        vector<vector<string>> ans = Anagrams(string_list);
        for(auto it: ans){
            for(auto it1: it){
                cout<<it1<<" ";
            }
            cout<<endl;
        }
    }