#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int maxi = findMax(v);
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }
    return maxi;
}

int minimumRateToEatBananasOP(vector<int> v, int h) {
    int low=1;
    int high=findMax(v);
    while(low<=high)
    {
        int mid=(high+low)/2;
        int reqtime=calculateTotalHours(v, mid);
        if(reqtime<=h){
            high=mid-1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananasOP(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}