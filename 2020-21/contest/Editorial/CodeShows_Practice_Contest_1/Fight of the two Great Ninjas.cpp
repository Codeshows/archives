#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,string> solve(ll n,ll *a){
	unordered_map<ll,ll> mpp;
	for(ll i=0;i<n;i++){
		mpp[a[i]]++;
	}
	ll c=0; //Uchiha
	for(auto w:mpp){
		c+=(w.second/2);
	}
	ll d = n/2 - c; //Naruto
	ll ans;
	string s;
	ans = d;
	if(d>c) s= "Naruto";
	else s = "Uchiha";

	return make_pair(ans,s);
}
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)cin>>a[i];
	pair<ll,string> p = solve(n,a);
	cout<<p.first<<endl;
	cout<<p.second<<endl;	
}
