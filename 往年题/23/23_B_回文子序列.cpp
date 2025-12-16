#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    unordered_map<int, int> ma;
    for (int i = 0; i <= n - 1; i++) {
        if (ma.count(a[i])) {
            if (a[i] == a[i - 1] && ma[a[i]] == 1) {
                ma[a[i]]++;
                continue;
            }
            cout << "YES" << endl;
            return;
        }
        ma[a[i]]++;
    }
    cout << "NO" << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}