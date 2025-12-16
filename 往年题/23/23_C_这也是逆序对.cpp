#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
class Tree {
    vector<int> tree;

public:
    Tree(int n) : tree(n) {}
    void add(int i, int val) {
        for (int x = i; x < tree.size(); x += lowbit(x)) tree[x] += val;
        return;
    }
    int pre(int x) {
        int res = 0;
        for (; x > 0; x -= lowbit(x)) res += tree[x];
        return res;
    }
};
void solve(int n) {
    vector<int> a(n);
    vector<int> b(n);
    vector<int> sorted;
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    for (int i = 0; i <= n - 1; i++) cin >> b[i];
    for (int i = 0; i <= n - 1; i++) sorted.push_back(a[i] - b[i]), sorted.push_back(b[i] - a[i]);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();
    Tree tree(m + 1);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int tem = lower_bound(sorted.begin(), sorted.end(), a[i] - b[i]) - sorted.begin() + 1;
        int pre = tree.pre(tem - 1);
        ans += 1LL * pre;
        int tem2 = lower_bound(sorted.begin(), sorted.end(), b[i] - a[i]) - sorted.begin() + 1;
        tree.add(tem2, 1);
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    string s;
    cin >> t;
    solve(t);
    while (cin >> s) {
        cout << s << endl;
        cin >> t;
        solve(t);
    }
    return 0;
}