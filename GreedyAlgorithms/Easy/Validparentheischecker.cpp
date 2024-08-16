#include<bits/stdc++.h>
using namespace std;
 bool checkValidString(string s) {
         int min=0,max=0;
         for(int i=0;i<s.length();i++){
            if(s[i]=='(') min++,max++;
            else if(s[i]==')') min--,max--;
            else{
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return false;
         }
         return min==0;
    }
 bool helper(string s,int ind,int cnt){
        if(cnt<0) return false;
        if(ind==s.length())
         {
            return cnt==0;
         }
        if(s[ind]=='(') return helper(s,ind+1,cnt+1);
        if(s[ind]==')') return helper(s,ind+1,cnt-1);
        
        return ((helper(s,ind+1,cnt+1))||
        (helper(s,ind+1,cnt-1))||
        (helper(s,ind+1,cnt)));
    }
    bool checkValidStringBP(string s) {
         return helper(s,0,0);
    }

    
int main(){
    string s="(*))";
    cout<<checkValidString(s);
}