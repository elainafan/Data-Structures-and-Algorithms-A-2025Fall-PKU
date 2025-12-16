#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    string s, t;
    map<string, string> ma;
    while (getline(cin, s)) {
        if (s.empty()) break;
        int n = s.length();
        int idx = -1;
        for (int i = 0; i <= n - 1; i++) {
            if (s[i] == ' ') {
                idx = i;
                break;
            }
        }
        string tem1 = s.substr(0, idx);
        string tem2 = s.substr(idx + 1);
        ma[tem2] = tem1;
    }
    while (cin >> t) {
        if (ma.count(t))
            cout << ma[t] << endl;
        else
            cout << "eh" << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}