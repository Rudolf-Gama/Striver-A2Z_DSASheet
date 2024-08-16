#include<bits/stdc++.h>
using namespace std;
 bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length()){
            return false;
        }
        string temp=s1+s1;
        //int pos=temp.find(s2);
        //return (pos<temp.length());
         return (temp.find(s2)!=-1);   //string::npos 1119 test cases passed.
    }

 bool areRotationsBP(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length()){
            return false;
        }
        queue<char>q1,q2;
        for(int i=0;i<s1.length();i++){
            q1.push(s1[i]);
            q2.push(s2[i]);
        }
        int k=q1.size();
        while(k--){
            if(q1==q2) return true;
            char ch= q2.front();
            q2.pop();
            q2.push(ch);
        }
        return false;
    }

    int main(){
        string s1,s2;
        cin>>s1>>s2;
        cout<<areRotations(s1,s2);
        return 0;
    }