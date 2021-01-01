#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
bool check(int a, int b, int x, int n)
{
    int c1 = 0, c2 = 0;
    vector<int> p, q;
    while (x)
    {
        p.push_back(x % 10);
        x = x / 10;
    }
    if (p.size() < 4)
    {
        p.push_back(0);
    }
    set<int> s;
    while (n)
    {
        q.push_back(n % 10);
        s.insert(n % 10);
        n = n / 10;
    }
    if (q.size() < 4)
    {
        q.push_back(0);
        s.insert(0);
    }
    if (s.size() != 4)
    {
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == q[i])
        {
            c1++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (p[i] == q[j] && i != j)
            {
                c2++;
                break;
            }
        }
    }
    if (a == c1 && b == c2)
        return true;
    return false;
}
void hehe()
{
    int n;
    cin >> n;
    vector<int> pos;
    for (int i = 99; i < 10000; i++)
    {
        pos.push_back(i);
    }
    while (n--)
    {
        int x, a, b;
        cin >> x >> a >> b;
        vector<int> temp;
        for (int i = 0; i < pos.size(); i++)
        {
            if (check(a, b, x, pos[i]))
            {
                temp.push_back(pos[i]);
            }
        }
        pos = temp;
    }
    if (pos.size() == 1)
    {
        int c = 0, num = pos[0];
        while (num)
        {
            c++;
            num /= 10;
        }
        if (c < 4)
        {
            cout << 0;
        }
        cout << pos[0]<<endl;
    }
    else if (pos.size() == 0)
    {
        cout << "Incorrect Information" << endl;
    }
    else
    {
        cout << "Make more guesses" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        hehe();
    }
    return 0;
}
