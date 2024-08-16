#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> v) {
   int n = v.size(); 
    vector<int> ls;
    for (int i = 0; i < n; i++) {
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[j] == v[i]) {
                    cnt++;
                }
            }
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }
    sort(ls.begin(),ls.end());
    return ls;
}

vector<int> majorityElementBP(vector<int> v) {
	
	int n=v.size();
	vector<int> ls;
	int mini = int(n / 3)+1 ;
	map<int,int> mpp;
	for(int i=0;i<n;i++){
	 mpp[v[i]]++;
	 
	 if(mpp[v[i]]==mini)
	  ls.push_back(v[i]);

	  if(ls.size()==2){
		  break;
	  }
	}
	sort(ls.begin(),ls.end());
	return ls;
}

vector<int> majorityElementOP(vector<int> v) {
	int n=v.size();
	vector<int> ls;
	int mini = int(n / 3)+1 ;
	int cnt1=0,cnt2=0;
	int e1,e2;
    for(int i=0;i<n;i++){
      if(cnt1==0 && v[i]!=e2){
		  cnt1=1;
		  e1=v[i];
	  }
	  else  if(cnt2==0 && v[i]!=e1){
		  cnt2=1;
		  e2=v[i];
	  }
	  else if(v[i]==e1){
		  cnt1++;
	  }
	   else if(v[i]==e2){
		  cnt2++;
	  }
	  else {
		  cnt1--,cnt2--;
	  }
	}
	int c1=0,c2=0;
	for(int i=0;i<n;i++){
		if(v[i]==e1) c1++;
		if(v[i]==e2) c2++;
	}
	if(c1>=mini) ls.push_back(e1);
	if(c2>=mini) ls.push_back(e2);

	sort(ls.begin(),ls.end());
	return ls;
}

int main(){
    vector<int> nums{1,1,1,1,3,3,3};
    vector<int> ans;
    ans=majorityElementBP(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}