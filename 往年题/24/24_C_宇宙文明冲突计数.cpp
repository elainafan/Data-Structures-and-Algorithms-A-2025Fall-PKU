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
    vector<pair<int, int>> ma(n);
    for (int i = 0; i <= n - 1; i++) cin >> ma[i].first >> ma[i].second;
    sort(ma.begin(), ma.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.second - x.first == y.second - y.first) return x.first + x.second < y.first + y.second;
        return x.first - x.second < y.first - y.second;
    });
    map<int, vector<int>> s;
    for (auto p : ma) s[p.first - p.second].push_back(p.first + p.second);
    vector<int> sorted;
    for (auto p : ma) sorted.push_back(p.first + p.second);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();
    Tree tree(m + 1);
    ll ans = 0;
    for (auto it = --(s.end());; it--) {
        for (int p : it->second) {
            int tem = lower_bound(sorted.begin(), sorted.end(), p) - sorted.begin() + 1;
            ll pre = tree.pre(tem - 1);
            ans += pre;
        }
        for (int p : it->second) {
            int tem = lower_bound(sorted.begin(), sorted.end(), p) - sorted.begin() + 1;
            tree.add(tem, 1);
        }
        if (it == s.begin()) break;
    }
    cout << 1LL * n * (n - 1) / 2 - ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    solve(n);
    while (cin >> s >> n) {
        cout << "===========" << endl;
        solve(n);
    }
    return 0;
}