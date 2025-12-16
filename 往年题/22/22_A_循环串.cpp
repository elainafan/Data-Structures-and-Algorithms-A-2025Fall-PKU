#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    string pattern;
    cin >> pattern;
    int m = pattern.size();
    vector<int> pi(m);
    int cnt = 0;
    for (int i = 1; i < m; i++) {
        char b = pattern[i];
        while (cnt && pattern[cnt] != b) cnt = pi[cnt - 1];
        if (pattern[cnt] == b) cnt++;
        pi[i] = cnt;
    }
    if (pi[m - 1] == 0)
        cout << m << endl;
    else if (m % (m - pi[m - 1]) == 0)
        cout << 0 << endl;
    else
        cout << (m - pi[m - 1]) - (m % (m - pi[m - 1])) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}