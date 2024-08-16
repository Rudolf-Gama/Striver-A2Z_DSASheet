#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}



vector<vector<int>> fourSumBP(vector<int>& nums, int target) {

    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hash;
            for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    int fourth=target-(sum);
                    if(hash.find(fourth)!=hash.end()){
                        vector<int> temp={nums[i],nums[j],nums[k],fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}



vector<vector<int>> fourSumOP(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1,l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums{2 ,2, 2 ,2 ,1 ,3};
    int target;
    cin>>target;
    vector<vector<int>> ans=fourSumOP(nums,target);
    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}

