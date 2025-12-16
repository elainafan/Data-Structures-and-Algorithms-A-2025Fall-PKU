#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int idx = -1;
    for (int i = 0; i <= n - 1; i++) {
        if (t[i] == '1') {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "test" << endl;
        return;
    }
    string tem1 = s.substr(idx);
    string tem2 = t.substr(idx);
    int m = tem1.size();
    vector<int> z(m);
    int l = 0, r = 0;
    for (int i = 1; i < m; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < m && tem1[z[i]] == tem1[i + z[i]]) {
            l = i, r = i + z[i];
            z[i]++;
        }
    }
    z[0] = m;
    int mixx = INT_MAX;
    for (int i = 0; i <= m - 1; i++) {
        if (tem2[i] == '1') mixx = min(mixx, z[i]);
    }
    for (int i = 0; i <= m - 1; i++) {
        if (tem2[i] == '0' && z[i] >= mixx) {
            cout << -1 << endl;
            return;
        }
    }
    if (mixx == 0)
        cout << -1 << endl;
    else
        cout << tem1.substr(0, mixx) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}