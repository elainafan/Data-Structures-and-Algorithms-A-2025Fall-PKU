#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
ll ans = 0;
void solve()
{
    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int>> a;
    vector<tuple<ll, int, int>> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= a[i].second; j++)
        {
            ma.emplace_back(a[i].first, -1, -1);
            q.push(make_tuple(a[i].first, -1, -1, ma.size() - 1));
        }
    }
    ll ans = 0;
    function<void(int, int)> dfs = [&](int idx, int d)
    {
        if (idx == -1)
            return;
        auto [x1, y1, z1] = ma[idx];
        if (y1 == -1 && z1 == -1)
        {
            ans += 1LL * x1 * d;
            return;
        }
        if (y1 != -1)
            dfs(y1, d + 1);
        if (z1 != -1)
            dfs(z1, d + 1);
        return;
    };
    while (!q.empty())
    {
        auto [x1, y1, z1, i1] = q.top();
        q.pop();
        auto [x2, y2, z2, i2] = q.top();
        q.pop();
        ma.emplace_back(x1 + x2, i1, i2);
        q.push(make_tuple(x1 + x2, i1, i2, ma.size() - 1));
        if (q.size() == 1)
        {
            dfs(ma.size() - 1, 0);
            cout << ans << endl;
            return;
        }
    }
    return;
}
int main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}