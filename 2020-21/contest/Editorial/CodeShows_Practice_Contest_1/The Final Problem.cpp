#include <bits/stdc++.h>
#define ll long long
#define mod (int)(1e9 + 7)
using namespace std;
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans*a)% mod;
        }
        a = (a*a)% mod;
        n /= 2;
    }
    return ans;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        int c=0;
        if(m<=-10 || m>9)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<10;i++) //(D1)
        {
            for(int j=1;j<10;j++) //(DN)
            {
                if((i-j)==m)
                    c++;
            }
        }
        if(n==2)
            cout<<(c%mod)<<endl;
        else
        {
            n=n-2;
            ll p=(power(10,n))% mod;
            p=(p*c)%mod;
            cout<<p<<endl;

        }
    }
    return 0;
}
