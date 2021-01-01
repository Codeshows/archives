#include<bits/stdc++.h>
#define int long long int
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	
	vector<int>Pre(n+1),Suf(n+1),arr(n+1);
	int gcd_=1;;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(i==1)gcd_=arr[i];
		else gcd_=__gcd(arr[i],gcd_);
		if(i==1)
			Pre[i]=arr[i];
		else 
			Pre[i]=gcd_;
	}	
	
	Suf[n]=arr[n];
	for(int i=n-1;i>=1;i--)
	{
		Suf[i]=__gcd(Suf[i+1],arr[i]);
	}
	
	if(k%2==0)
	{
		cout<<"Eshaan pays\n";
	}
	else
	{
		if(Suf[2]>1 || Pre[n-1]>1)
		{
			cout<<"Sanskar pays\n";
		}
		else
		{
			bool S_P=false;
			for(int i=2;i<=n-1;i++)
			{
				int Gcd_except_i=__gcd(Pre[i-1],Suf[i+1]);
				if(Gcd_except_i>1)
				{
					cout<<"Sanskar pays\n";
					S_P=true;
					break;
				}
			}
			if(!S_P)
			{
				cout<<"Eshaan pays\n";
			}
		}
	}
	return ;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}