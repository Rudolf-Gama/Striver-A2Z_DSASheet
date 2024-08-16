#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
int i=0;
for(int j=1;j<n;j++){
	if(arr[i]!=arr[j]){
		arr[i+1]=arr[j];
		i++;
	}
}
return i+1;
}

int main(){
   vector<int> v{2,2,3,4,4,7,8,8};
    cout<<removeDuplicates(v,v.size());
    return 0; 
}