#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n;
int get(int x, vector<int>& fa) {
    if (fa[x] == x) return fa[x];
    return fa[x] = get(fa[x], fa);
}
void merge(int x, int y, vector<int>& fa) {
    fa[get(x, fa)] = get(y, fa);
    return;
}
void solve() {
    vector<int> fa(n);
    vector<vector<int>> ma2(n, vector<int>(n));
    vector<tuple<int, int, int>> ma;
    for (int i = 0; i <= n - 1; i++) fa[i] = i;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {
            cin >> ma2[i][j];
            if (ma2[i][j] != 0 && j >= i + 1) ma.emplace_back(ma2[i][j], i, j);
        }
    }
    sort(ma.begin(), ma.end());
    int ans = 0;
    for (int i = 0; i < ma.size(); i++) {
        auto [z, x, y] = ma[i];
        int dx = get(x, fa), dy = get(y, fa);
        if (dx == dy) continue;
        ans += z;
        merge(x, y, fa);
    }
    cout << ans << endl;
    return;
}
int main() {
    while (cin >> n) {
        solve();
    }
    system("pause");
    return 0;
}