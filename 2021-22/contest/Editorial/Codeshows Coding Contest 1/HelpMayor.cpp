#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
const ll P = 10000;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    auto fc = [](string s) -> ll
    {
        ll res = 0;
        int co = -1;
        rep(i, s.size())
        {
            if (s.at(i) == '.')
            {
                co = 0;
            }
            else
            {
                res *= 10;
                res += s.at(i) - '0';
                if (co != -1)
                    co++;
            }
        }
        if (co == -1)
            co = 0;
        rep(i, 4 - co) res *= 10;
        return res;
    };
    ll x = fc(a) % P, y = fc(b) % P, r = fc(c);
    ll st = x - r;
    if (st < 0)
    {
        st = (abs(st) + P - 1) / P * P * -1;
    }
    else
    {
        st /= P;
    }

    auto lf = [=](ll d) -> ll
    {
        ll p = r * r - d * d;
        ll res = sqrt(p) + 5;
        while ((res - 1) * (res - 1) > p)
            res--;
        res--;
        return res;
    };

    ll ans = 0;
    for (ll now = st; now <= x + r; now += P)
    {
        ll d = abs(now - x);
        if (r * r - d * d < 0)
            continue;
        ll h = lf(d);
        ll top = y + h, btm = y - h;

        if (top >= 0)
            top = top / P * P;
        else
            top = (abs(top) + P - 1) / P * P * -1;

        if (btm >= 0)
            btm = (btm + P - 1) / P * P;
        else
            btm = abs(btm) / P * P * -1;

        if (top < btm)
            continue;
        ans += (top - btm) / P + 1;
    }
    cout << ans << endl;
    return 0;
}