#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ma(n + 1);
    vector<int> deg(n + 1, 0);
    vector<int> res;
    int x, y;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        ma[x].push_back(y);
        deg[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int node = q.top();
        q.pop();
        res.push_back(node);
        for (int p : ma[node]) {
            if (--deg[p] == 0) q.push(p);
        }
    }
    for (int p : res) cout << 'v' << p << ' ';
    return;
}
int main() {
    solve();
    system("pause");
    return 0;
}