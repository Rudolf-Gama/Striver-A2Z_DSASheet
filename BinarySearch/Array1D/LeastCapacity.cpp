#include<bits/stdc++.h>
using namespace std;

int calcudays(vector<int> &weights, int cap){
    int load=0,day=1;
    for(int i=0;i<weights.size();i++){
        load+=weights[i];
        if(load>cap){
            day++;
            load=weights[i];
        }
    }
    return day;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;
        int reqday=calcudays(weights,mid);
        if(reqday<=d)
         high=mid-1;
         else 
         low=mid+1;
    }
    return low;
}
int leastWeightCapacityBF(vector<int> &weights, int d)
{
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);

    for(int i=low;i<=high;i++){
        int reqday=calcudays(weights,i);
        if(reqday<=d)
        return i;
    }
}

int main(){
    vector<int> weights{1 ,2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d;
    cin>>d;
    cout<<"Minimum capacity "<<leastWeightCapacityBF(weights,d);
    return 0;
}