 #include<bits/stdc++.h>
 using namespace std;


 string reverseWords(string S) 
    { 
       stack<string> st;
       string str="";
       S+='.';
       for(int i=0;i<S.length();i++){
           if(S[i]=='.'){
               st.push(str);
               str="";
           }
          else str+=S[i];
       }
       
       string ans;
       while(st.size()!=1){
           ans+=st.top()+'.';
           st.pop();
       }
       ans+=st.top();
       st.pop();
       return ans;
    } 

     string reverseWordsOP(string S) 
    { 
      string ans;
      string temp;
      int l=0;
      int r=S.length()-1;
      while(l<=r){
          char ch=S[l];
          if(ch!='.'){
              temp+=ch;
          }
          else if(ch=='.'){
              if(ans!="") ans=temp+"."+ans;
              else ans=temp;
            temp="";  
          }
          l++;
      }
      if(temp!=""){
          if(ans!="") ans=temp+"."+ans;
          else ans=temp;
      }
      return ans;
    } 
    int main(){
        string s;
        cin>>s;
        cout<<reverseWordsOP(s);
        return 0;
    }