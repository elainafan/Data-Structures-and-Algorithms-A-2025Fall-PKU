#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
class UnionFind {
    vector<int> fa;
    vector<int> sz;

public:
    int cc;
    UnionFind(int n) : fa(n), cc(n), sz(n, 1) {
        for (int i = 0; i <= n - 1; i++) fa[i] = i;
    }
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int dx = find(x), dy = find(y);
        if (dx == dy) return false;
        fa[dx] = dy;
        sz[dy] += sz[dx];
        cc--;
        return true;
    }
    int get_size(int x) { return sz[find(x)]; }
};
void solve() {
    int n;
    cin >> n;
    int x, y, z;
    vector<tuple<int, int, int>> ma;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y >> z;
        ma.emplace_back(x - 1, y - 1, z);
    }
    sort(ma.begin(), ma.end(), [&](const tuple<int, int, int> &x, const tuple<int, int, int> &y) {
        auto [x1, y1, z1] = x;
        auto [x2, y2, z2] = y;
        return z1 < z2;
    });
    UnionFind u(n);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        auto [x, y, z] = ma[i];
        ans += 1LL * z;
        int tem1 = u.get_size(x), tem2 = u.get_size(y);
        if (u.merge(x, y)) {
            ans += 1LL * (z + 1) * (tem1 * tem2 - 1);
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}