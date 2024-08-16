#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {
    map<int,int> mpp;
	for(int i=0;i<v.size();i++){
		mpp[v[i]]++;
	}
    for(auto it: mpp){
		if(it.second>(v.size()/2))
		return it.first;
	}
return -1;
}

int majorityElementOP(vector<int> v) {
	int n=v.size();
   int cnt=0,ele;
   for(int i=0;i<n;i++){
	   if(cnt==0){
		   cnt=1;
		   ele=v[i];
	   }
	   else if(v[i]==ele) cnt++;
	   else cnt--;
   }
   int cnt2=0;
   for(int i=0;i<n;i++){
	   if(v[i]==ele) cnt2++;
   }
   if(cnt2>n/2) return ele;
   return -1;
}

int main(){
    vector<int> v{1,2,5,3,4,5,5,5};
    cout<<majorityElementOP(v);
    return 0;
}