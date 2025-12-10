#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, x;
    cin >> n;
    multiset<int> s1;
    multiset<int> s2;  // s1是较小的
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (s1.size() == s2.size()) {
            s1.insert(x);
            if (!s2.empty() && *(--s1.end()) > *(s2.begin())) {
                int tem1 = *(--s1.end());
                s1.erase(--s1.end());
                int tem2 = *(s2.begin());
                s2.erase(s2.begin());
                s1.insert(tem2);
                s2.insert(tem1);
            }
        } else {
            s2.insert(x);
            if (!s2.empty() && *(--s1.end()) > *(s2.begin())) {
                int tem1 = *(--s1.end());
                s1.erase(--s1.end());
                int tem2 = *(s2.begin());
                s2.erase(s2.begin());
                s1.insert(tem2);
                s2.insert(tem1);
            }
        }
        if (i % 2 == 1) cout << *(--s1.end()) << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}