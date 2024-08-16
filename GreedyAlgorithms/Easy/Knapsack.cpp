#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool comp(Item a,Item b){
        return ((double)a.value/(double)a.weight)>=((double)b.value/(double)b.weight);
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,comp);
        double totalval=0.0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=w){
                totalval+=(double)(arr[i].value);
                w-=arr[i].weight;
            }
            else{
                totalval+=((double)arr[i].value/(double)arr[i].weight)*(double)w;
                break;
            }
        }
        return totalval;
    }

int main(){
    int w=90;
    Item arr[]={{100,20},{60,10},{100,50},{200,50}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<fractionalKnapsack(w,arr,n);
    return 0;
}