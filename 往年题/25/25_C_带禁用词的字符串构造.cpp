#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve()
{
    int la, lb, k, q;
    cin >> la >> lb >> k >> q;
    string a, b;
    cin >> a >> b;
    char x, y;
    ll op;
    vector<set<int>> s(26);
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        s[x - 'a'].insert(y - 'a');
    }
    vector<string> pre(26, "");
    vector<ll> prel(26, 0);
    for (int i = 0; i <= 25; i++)
    {
        for (int j = 0; j < lb; j++)
        {
            if (s[i].count(b[j] - 'a'))
                continue;
            pre[i] += (char)('a' + i);
            pre[i] += b[j];
        }
        prel[i] = pre[i].size();
    }
    vector<ll> pd(la + 1, 0);
    for (int i = 1; i <= la; i++)
        pd[i] = pd[i - 1] + prel[a[i - 1] - 'a'];
    for (int i = 1; i <= q; i++)
    {
        cin >> op;
        int x = lower_bound(pd.begin(), pd.end(), op + 1) - pd.begin();
        cout << pre[a[x - 1] - 'a'][op - pd[x - 1]] << endl;
    }
    return;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}