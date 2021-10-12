#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,t,x;
	cin>>n>>x>>t;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	 long long int i=0,j=0,sum=arr[0],ans=n+1;
        while(i<=j && j<n)
        {
            if(sum>x)
            {
                sum-=arr[i];
                ans=min(ans,j-i+1);
                i++;
            }
            else
            {
				j++;
				if(j<n)
				{
				sum+=arr[j];
				}
            }
        }
	    cout<<ans*t<<endl;
}