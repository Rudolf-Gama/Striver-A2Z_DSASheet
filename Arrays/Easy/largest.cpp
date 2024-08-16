#include<bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &arr, int n) {
   int largest=arr[0];
   for(int i=1;i<n;i++)
   {
       if(arr[i]>largest) {
           largest=arr[i];
       }
   }
   return largest;
}
int main(){
    vector<int> v{2,5,88,99,3};
    int a=largestElement(v,v.size());
    cout<<a;
    return 0; 
}