#include<bits/stdc++.h>
using namespace std;
int totalFruits(int N, vector<int> &fruits) {
        int maxlen=0;
        for(int i=0;i<N;i++){
            unordered_set<int> st;
            for(int j=i;j<N;j++){
                st.insert(fruits[j]);
                if(st.size()<=2){
                    maxlen=max(maxlen,j-i+1);
                }
                else break;
            }
        }
        return maxlen;
    }
    int totalFruitsBP(int N, vector<int> &fruits) {
        int l=0,r=0,maxlen=0;
        unordered_map<int,int>mpp;
        while(r<N){
            mpp[fruits[r]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<=2){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }

    int totalFruitsOP(int N, vector<int> &fruits) {
        int l=0,r=0,maxlen=0;
        unordered_map<int,int>mpp;
        while(r<N){
            mpp[fruits[r]]++;
           
            if(mpp.size()>2)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);
                l++;
            }
            else{
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
int main(){
    vector<int>fruits={ 0, 1, 2, 2, 2, 2 };
    cout<<totalFruitsOP(fruits.size(),fruits);
    return 0;
}