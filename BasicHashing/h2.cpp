#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int hash[26]={0};
    for(int i=0;i<s.size();i++) hash[s[i]-'a']+=1;

    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<"Occurance of "<<ch<<" is "<<hash[ch-'a']<<endl;
    }

    return 0;
}