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
        sz[dy] += sz[x];
        cc--;
        return true;
    }
    int get_size(int x) { return sz[find(x)]; }
};
void solve(int n, int m) {
    int ans = n;
    int x, y;
    vector<set<int>> ma(n);
    for (int i = 0; i <= m - 1; i++) {
        cin >> x >> y;
        ma[x - 1].insert(y - 1);
        ma[y - 1].insert(x - 1);
    }
    map<int, int> unvis;
    int cnt = 0;
    for (int i = 0; i <= n - 1; i++) unvis[i] = 1;
    function<void(int)> bfs = [&](int x) -> void {
        queue<int> q;
        q.push(x);
        unvis.erase(unvis.find(x));
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto it = unvis.begin();
            while (it != unvis.end()) {
                int p = it->first;
                if (ma[node].count(p))
                    it++;
                else {
                    q.push(p);
                    it = unvis.erase(it);
                }
            }
        }
        return;
    };
    for (int i = 0; i <= n - 1; i++) {
        if (unvis.count(i)) {
            bfs(i);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    solve(n, m);
    string s;
    while (cin >> s) {
        cout << "===========" << endl;
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}