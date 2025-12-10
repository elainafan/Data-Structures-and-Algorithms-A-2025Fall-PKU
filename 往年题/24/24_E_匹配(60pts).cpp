#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    string s, p;
    cin >> s >> p;
    int n = p.length();
    vector<int> ss;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] == '1') ss.push_back(i);
    }
    int m = ss.size();
    if (m == 0) {
        cout << "test" << endl;
        return;
    }
    if (m == 1) {
        cout << s.substr(ss[0]) << endl;
        return;
    }
    string ans = "";
    bool flag = true;
    for (int j = 1; j <= m - 1; j++) {
        if (s[ss[j]] != s[ss[j - 1]]) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    int l = 1, r = n - ss[0] + 1, mid;
    function<bool(int)> check = [&](int mid) -> bool {
        string tem = s.substr(ss[0], mid);
        for (int i = 1; i < ss.size(); i++) {
            string tem1 = s.substr(ss[i], mid);
            if (tem1 != tem) return false;
        }
        return true;
    };
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << s.substr(ss[0], l) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}