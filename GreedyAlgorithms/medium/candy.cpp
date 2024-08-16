#include<bits/stdc++.h>
using namespace std;
int minCandyBP(int N, vector<int> &ratings) {
        // code here
        vector<int> left(N);
        left[0]=1;
        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else left[i]=1;
        }
        int sum=left[N-1];
        int right=1;
        for(int i=N-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right++;
            }
            else right=1;
           sum+=max(left[i],right);
        }
        return sum;
    }

int minCandyBF(int N, vector<int> &ratings) {
        // code here
        vector<int> left(N);
        vector<int> right(N);
        left[0]=1;
        right[N-1]=1;
        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else left[i]=1;
        }
        for(int i=N-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else right[i]=1;
        }
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }

int minCandyOP(int N, vector<int> &ratings) {
        // code here
        int sum=1;
        int i=1;
        while(i<N){
            if(ratings[i]==ratings[i-1])
            {
                sum++;
                i++;
                continue;
            }
            int peak=1;
            while(i<N && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<N && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }

int main(){
    vector<int> ratings{1, 2, 2};
    cout<<minCandyOP(ratings.size(),ratings)<<endl;
    return 0;
}