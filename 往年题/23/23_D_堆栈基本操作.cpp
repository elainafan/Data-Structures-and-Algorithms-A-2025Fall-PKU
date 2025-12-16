#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    stack<int> s;
    vector<string> ans;
    int x;
    int cnt = 0;
    for (int i = 0; i <= n - 1; i++) {
        cin >> x;
        if (x > n || x < 1) {
            cout << "NO" << endl;
            return;
        }
        if (!s.empty() && s.top() == x) {
            s.pop();
            ans.push_back("POP " + to_string(x));
            continue;
        } else {
            if (x < cnt) {
                cout << "NO" << endl;
                return;
            }
            while (cnt < x) {
                s.push(++cnt);
                ans.push_back("PUSH " + to_string(cnt));
            }
            s.pop();
            ans.push_back("POP " + to_string(x));
        }
    }
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        ans.push_back("POP " + to_string(node));
    }
    for (auto p : ans) cout << p << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}