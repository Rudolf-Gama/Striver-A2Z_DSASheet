#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(int i=0;i<N;i++){
            if(asteroids[i]>0)
             st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                st.pop();
                if(!st.empty() && st.top()==abs(asteroids[i]))
                st.pop();
                else if(st.empty() || st.top()<0)
                st.push(asteroids[i]);
             }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> asteroidCollisionOP(int N, vector<int> &asteroids) {
        // code here using vectors
        vector<int> st;
        for(int i=0;i<N;i++){
            if(asteroids[i]>0)
             st.push_back(asteroids[i]);
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i]))
                st.pop_back();
                if(!st.empty() && st.back()==abs(asteroids[i]))
                st.pop_back();
                else if(st.empty() || st.back()<0)
                st.push_back(asteroids[i]);
             }
        }
        return st;
    }
    int main(){
        vector<int> arr{4,7,1,1,2,-3,-7,17,15,-16};
        vector<int> ans=asteroidCollision(arr.size(),arr);
        return 0;
    }