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
    ll pre(int x) {
        int res = 0;
        for (; x > 0; x -= lowbit(x)) res += 1LL * tree[x];
        return res;
    }
};
void solve(int n) {
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    auto sorted = a;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    ll ans = 0;
    int m = sorted.size();
    Tree tree(m + 1);
    for (int i = n - 1; i >= 0; i--) {
        int tem = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin() + 1;
        ll pre = tree.pre(tem - 1);
        ans += pre;
        tree.add(tem, 1);
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    while (cin >> t) {
        if (t == 0) break;
        solve(t);
    }
    return 0;
}