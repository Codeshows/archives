#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
    while(t--){
            long long int n;
            cin>>n;
        	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	 reverse(arr,arr+n);
     vector<int>ans;
     int j=0;
     for(auto i=0;i<=n;i++){
         while(j<n && arr[j]<=i-j-1){
             j++;
         }
         ans.push_back(n+1-j);
     }
     for(auto i:ans){
         cout<<i<<" ";
     }
     cout<<"\n";

    }

}