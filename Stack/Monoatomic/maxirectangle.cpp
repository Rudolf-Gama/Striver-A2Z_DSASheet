#include<bits/stdc++.h>
using namespace std;
const int MAX = 4; 
int getMaxAreaOP(int arr[], int n)
    {
        // Your code here
        stack<int> st;
        int area=0L;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1 :st.top();
                area=max(area,arr[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
                int ele=st.top();
                st.pop();
                int nse=n;
                int pse=st.empty()?-1 :st.top();
                area=max(area,arr[ele]*(nse-pse-1));
        }
        return area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int presum[n][m];
        int maxarea=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=M[j][i];
                if(M[j][i]==0)
                sum=0;
                presum[j][i]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,getMaxAreaOP(presum[i],m));
        }
        return maxarea;
    }
    
    int main(){
        int arr[MAX][MAX]={{0 ,1, 1 ,0},
         {1, 1, 1 ,1},
         {1, 1, 1 ,1},
         {1 ,1 ,0 ,0}};
        cout<<maxArea(arr,MAX,MAX);
        return 0;
    }