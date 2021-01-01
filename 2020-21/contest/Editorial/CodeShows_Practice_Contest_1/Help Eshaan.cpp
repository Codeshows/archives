#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("in11.txt","r",stdin);
  freopen("out11.txt","w",stdout);
  #endif
    int m,s,t;
    cin>>m>>s>>t;
    if(t>=s)
    {
      t=s-1;
      cout<<floor((m*t)/s);
    }
    else
    {
      int x=t;
      cout<<floor((m*x)/s)-m*floor(x/s);  
    }
    return 0;
}