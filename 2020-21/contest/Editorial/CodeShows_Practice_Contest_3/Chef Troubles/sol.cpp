#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

ll price[1005][1005], quality[1005][1005];

void cp()
{
    int n, m;
    ll budget;
    cin >> n >> m >> budget;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> price[i][j] >> quality[i][j];
    ll best = -1;
    ll lo = 0, hi = 1e9;
    while(lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        // try to keep quality at least mid
        // pick the smallest price
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            ll cheap = INT_MAX;
            for(int j = 0; j < m; j++) // minimise cost of ingredient i if quality is at least mid
                if(quality[j][i] >= mid)
                    cheap = min(cheap, price[j][i]);
            sum += cheap;
        }
        if(sum <= budget)
            best = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << best << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}