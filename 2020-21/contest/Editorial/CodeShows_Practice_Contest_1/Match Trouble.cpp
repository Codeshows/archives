#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 301;

vector<int> prime;
vector<bool> is_prime;

ll comb[100005][5];
ll fact[5], mask_of[MAXN];
set<ll> dis;
vector<ll> masks;

void sieve(int n)
{
    is_prime.resize(n + 1);
    fill(all(is_prime), true);
    is_prime[1] = false;
    for(int i = 2; i < sz(is_prime); i++)
    {
        if(is_prime[i])
            prime.pb(i);
        for(int j = 0; j < sz(prime) && i * prime[j] < sz(is_prime); j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
}

void init(int n)
{
    // Combinatorics stuff
    for(int i = 0; i < 100005; i++)
        comb[i][0] = 1;
    for(int i = 1; i < 100005; i++)
        for(int j = 1; j < 5; j++)
            comb[i][j] = (comb[i - 1][j] + 0LL + comb[i - 1][j - 1]) % mod;
    fact[0] = 1;
    for(int i = 1; i < 5; i++)
        fact[i] = fact[i - 1] * i;

    sieve(n);
    // Generate unique masks
    for(int i = 1; i < n; i++)
    {
        ll mask = 0;
        for(int j = 0; j < sz(prime); j++)
        {
            int temp = i;
            int c = 0;
            while(temp % prime[j] == 0)
                temp /= prime[j], c = (c + 1) % 2;
            mask |= ((c * 1LL) << (j * 1LL));
        }
        mask_of[i] = mask;
        dis.insert(mask);
    }
    masks = vector<ll>(all(dis));
}

map<ll, int> freq;
// masks^3 * log(masks)
void cp()
{
    int n;
    cin >> n;

    for(int i = 0, x; i < n; i++)
        cin >> x, freq[mask_of[x]]++;
    sort(all(masks));

    ll ans = 0;
    for(int i = 0; i < sz(masks); i++)
    {
        for(int j = i; j < sz(masks); j++)
        {
            for(int k = j; k < sz(masks); k++)
            {
                ll last = masks[i] ^ masks[j] ^ masks[k];
                auto it = lower_bound(begin(masks) + k, end(masks), last);
                if(it != end(masks) && *it == last)
                {
                    map<ll, int> cnt;
                    cnt[masks[i]]++, cnt[masks[j]]++, cnt[masks[k]]++, cnt[last]++;
                    ll me = 24;
                    for(auto &x : cnt)
                    {
                        me *= comb[freq[x.ff]][x.ss];
                        me %= mod;
                    }
                    ans += me;
                    ans %= mod;
                }
            }

        }
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init(MAXN);
    while(t--)
    {
        cp();
    }
    return 0;
}