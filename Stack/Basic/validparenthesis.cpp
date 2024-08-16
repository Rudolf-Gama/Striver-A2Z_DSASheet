#include<bits/stdc++.h>
using namespace std;
bool ispar(string x)
    {
        // Your code here
        stack<int>st;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='(' || x[i]=='[' || x[i]=='{')
            st.push(x[i]);
            else{
                if(st.empty())
                    return false;
                char ch=st.top();
                st.pop();
                if((x[i]=='}' && ch=='{')||
                   (x[i]==']' && ch=='[')||
                   (x[i]==')' && ch=='('))
                continue;
                else return false;
            }
        }
        return st.empty();
    }

    int main(){
        string x;
        cin>>x;
        cout<<ispar(x);
        return 0;
    }
