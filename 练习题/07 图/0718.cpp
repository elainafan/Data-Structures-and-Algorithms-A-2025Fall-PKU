#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void tarjan(int x, int fa, int& tot, vector<int>& dfn, vector<int>& low, vector<int>& belong, vector<int>& in_stack, vector<int>& sz,
            vector<vector<int>>& ma, stack<int>& s) {
    dfn[x] = low[x] = ++tot;
    s.push(x);
    in_stack[x] = 1;
    for (int y : ma[x]) {
        if (!dfn[y]) {
            tarjan(y, x, tot, dfn, low, belong, in_stack, sz, ma, s);
            low[x] = min(low[x], low[y]);
        } else if (in_stack[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        int y;
        do {
            y = s.top();
            s.pop();
            in_stack[y] = 0;
            belong[y] = x;
            sz[x]++;
        } while (y != x);
    }
    return;
}
void solve() {
    int n, m, x, y;
    cin >> n >> m;
    n++;
    vector<int> dfn(n);
    vector<int> low(n);
    vector<int> belong(n);
    vector<int> sz(n);
    vector<int> in_stack(n);
    vector<vector<int>> ma(n);
    vector<vector<int>> ma2(n);
    vector<int> deg(n, 0);  // 这里是出度
    stack<int> s;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        ma[x].push_back(y);
    }
    for (int i = 1; i <= n - 1; i++) {
        if (!dfn[i]) {
            int tot = 0;
            tarjan(i, -1, tot, dfn, low, belong, in_stack, sz, ma, s);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j : ma[i]) {
            if (belong[i] == belong[j]) continue;
            ma2[belong[i]].push_back(belong[j]);
            deg[belong[i]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (i == belong[i] && deg[i] == 0) {
            cnt++;
            ans += sz[i];
        }
    }
    if (cnt >= 2)
        cout << 0 << endl;
    else
        cout << ans << endl;
    return;
}
int main() {
    solve();
    system("pause");
    return 0;
}