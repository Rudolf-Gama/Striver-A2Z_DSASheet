#include<bits/stdc++.h>
using namespace std;
long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        long long maxscore=0L;
        long long lsum=0L;
        long long rsum=0L;
        for(int i=0;i<k;i++) lsum+=cardPoints[i];
        maxscore=lsum;
        int r=N-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            maxscore=max(maxscore,(lsum+rsum));
        }
        return maxscore;
    }

    
int main(){
    vector<int> arr{6,2,3,4,7,2,1,7,1};
    int k;
    cin>>k;
    cout<<maxScore(arr,arr.size(),k);
    return 0;
}