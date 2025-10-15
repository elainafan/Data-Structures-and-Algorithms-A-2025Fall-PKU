#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n;
void solve() {
    n++;
    int m, x, y;
    vector<vector<int>> ma(n, vector<int>(n, INT_MAX / 2));
    for (int i = 1; i <= n - 1; i++) ma[i][i] = 0;
    for (int i = 1; i <= n - 1; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> x >> y;
            ma[i][x] = y;
        }
    }
    for (int k = 1; k <= n - 1; k++) {
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= n - 1; j++) {
                ma[i][j] = min(ma[i][j], ma[i][k] + ma[k][j]);
            }
        }
    }
    int ans = INT_MAX;
    int maxx = -1;
    for (int i = 1; i <= n - 1; i++) {
        int temp = INT_MIN;
        bool pd = true;
        for (int j = 1; j <= n - 1; j++) {
            if (ma[i][j] == INT_MAX / 2) {
                pd = false;
                break;
            }
            temp = max(temp, ma[i][j]);
        }
        if (pd && temp < ans) {
            ans = temp;
            maxx = i;
        }
    }
    if (ans == INT_MAX)
        cout << "disjoint" << endl;
    else
        cout << maxx << ' ' << ans << endl;
    return;
}
int main() {
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
    system("pause");
    return 0;
}