#include<bits/stdc++.h>
using namespace std;

double minimiseMaxDistanceBF(vector<int> &arr, int k){	
	int n=arr.size();
	vector<int> howmany(n-1,0);

	for(int g=1;g<=k;g++){
		long double sec=-1;
		int index=-1;

		for(int i=0;i<n-1;i++){
            long double diff=arr[i+1]-arr[i];
			long double seclength=diff/(howmany[i]+1);
			if(seclength>sec){
				sec=seclength;
				index=i;
			}
		}
		howmany[index]++;
	}

	long double maxsec=-1;
	for(int i=0;i<n-1;i++){
		 long double diff=arr[i+1]-arr[i];
		 long double seclength=diff/(howmany[i]+1);
		maxsec=max(maxsec,seclength);
	}
	return maxsec;
}

double minimiseMaxDistanceBP(vector<int> &arr, int k){
	// Write your code here.	
	int n=arr.size();
	priority_queue<pair<long double,int>> pq;
	for(int i=0;i<n-1;i++){
		long double diff=arr[i+1]-arr[i];
		pq.push({diff,i});
	}
    
	vector<int> howmany(n-1,0);
	for(int g=1;g<=k;g++){
		auto tp=pq.top();
		pq.pop();
		int i=tp.second;
        howmany[i]++;
		long double diff=arr[i+1]-arr[i];
		long double sec=diff/((long double)(howmany[i]+1));
        pq.push({sec,i});
	}
	return pq.top().first;
}

#include<bits/stdc++.h>
int noofstation(vector<int> &arr,int n,double mid){
	int cnt=0;
	for(int i=0;i<n-1;i++){
		double diff=arr[i+1]-arr[i];
		cnt+=ceil(diff/mid) -1;
	}
	return cnt;
}
double minimiseMaxDistanceOP(vector<int> &arr, int k){
	int n=arr.size();
	double low=0.0;
	double high=arr[n-1]-arr[0];
	while(high-low> 1e-6){
		double mid=low+(high-low)/2.0;
		int cnt=noofstation(arr,n,mid);
		if(cnt<=k)
		high=mid;
		else 
		low=mid;
	}
	return high;
}

int main(){
    vector<int> arr{1,13,17,23};
    int k;
    cin>>k;
    cout<<minimiseMaxDistanceOP(arr,k);
    return 0;
}

