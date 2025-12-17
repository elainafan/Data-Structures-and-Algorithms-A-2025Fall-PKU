#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
class UnionFind
{
    vector<int> fa;
    vector<int> sz;

public:
    int cc;
    UnionFind(int n) : fa(n), sz(n, 1), cc(n)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int get(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = get(fa[x]);
    }
    bool merge(int x, int y)
    {
        int dx = get(x), dy = get(y);
        if (dx == dy)
            return false;
        sz[dy] += sz[dx];
        fa[dx] = dy;
        return true;
    }
    int size(int x)
    {
        return sz[get(x)];
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    int a, b;
    ll ans = 0;
    UnionFind u(n);
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b;
        int x = a - 1, y = b - 1;
        int tem1 = u.size(x), tem2 = u.size(y);
        if (u.merge(x, y))
        {
            ans += 1LL * (tem1 + tem2) * (tem1 + tem2 - 1) / 2 - 1LL * tem1 * (tem1 - 1) / 2 - 1LL * tem2 * (tem2 - 1) / 2;
        }
        cout << ans << endl;
    }
    return;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}