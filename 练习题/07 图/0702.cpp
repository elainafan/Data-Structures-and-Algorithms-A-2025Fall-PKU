#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n, k;
void dfs(int t, int cnt, int k, int& ans, vector<vector<char>>& ma, vector<bool>& pd) {
    if (cnt == k) {
        ans++;
        return;
    }
    if (t == n) return;
    for (int i = 0; i <= n - 1; i++) {
        if (ma[t][i] == '#' && !pd[i]) {
            pd[i] = true;
            dfs(t + 1, cnt + 1, k, ans, ma, pd);
            pd[i] = false;
        }
    }
    dfs(t + 1, cnt, k, ans, ma, pd);
    return;
}
void solve() {
    vector<vector<char>> ma(n, vector<char>(n));
    vector<bool> pd(n, false);
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) cin >> ma[i][j];
    }
    int ans = 0;
    dfs(0, 0, k, ans, ma, pd);
    cout << ans << endl;
    return;
}
int main() {
    while (cin >> n >> k) {
        if (n == -1 && k == -1) break;
        solve();
    }
    system("pause");
    return 0;
}