#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr){
	int n = arr.size();
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
int getSingleElementBE(vector<int> &arr) {
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}

int main(){
     vector<int> arr = {4,4,1,5,5, 1};
     int ans=getSingleElementBE(arr);
     cout<<ans;
    return 0;
}