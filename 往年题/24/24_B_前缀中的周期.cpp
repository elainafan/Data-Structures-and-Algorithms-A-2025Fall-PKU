#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve(int n) {
    string s;
    cin >> s;
    vector<int> pi(n);
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        char b = s[i];
        while (cnt && s[cnt] != b) {
            cnt = pi[cnt - 1];
        }
        if (s[cnt] == b) cnt++;
        pi[i] = cnt;
    }
    for (int i = 0; i <= n - 1; i++) {
        if (pi[i] != 0 && (i + 1) % (i + 1 - pi[i]) == 0) {
            cout << i + 1 << ' ' << (i + 1) / (i + 1 - pi[i]) << endl;
        }
    }
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int cnt = 0;
    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        cnt++;
        cout << "Test case #" << cnt << endl;
        solve(n);
    }
    return 0;
}