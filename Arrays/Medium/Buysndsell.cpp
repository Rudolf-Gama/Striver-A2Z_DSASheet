#include<bits/stdc++.h>
using namespace std;
int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int maxprofit=0;
    int cost,mini=prices[0];

    for(int i=1;i<prices.size();i++){
           cost=prices[i]-mini;
           maxprofit=max(cost,maxprofit);
           mini=min(mini,prices[i]);
    }
  return maxprofit;
}

int main(){
    vector<int> prices{7,1,5,3,9,6,4};
    cout<<bestTimeToBuyAndSellStock(prices);
}