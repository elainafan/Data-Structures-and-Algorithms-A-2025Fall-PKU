#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};
void solve() {
    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int>> ma(n, {-1, -1});
    vector<int> leaf;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        if (ma[x - 1].first == -1)
            ma[x - 1].first = y - 1;
        else
            ma[x - 1].second = y - 1;
    }
    vector<pair<int, int>> sz(n);
    vector<pair<ll, ll>> cnt(n);
    function<pair<int, ll>(int)> dfs = [&](int x) -> pair<int, ll> {
        if (x == -1) return {0, 0};
        if (ma[x].first == -1 && ma[x].second == -1) return {1, 0};
        auto [l1, r1] = dfs(ma[x].first);
        auto [l2, r2] = dfs(ma[x].second);
        sz[x].first = l1, sz[x].second = l2;
        cnt[x].first = r1;
        cnt[x].second = r2;
        return {l1 + l2 + 1, 1LL * r1 + r2 + abs(l1 - l2)};
    };
    dfs(0);
    function<ll(int)> dfs2 = [&](int x) -> ll {
        if (x == -1) return 0;
        if (ma[x].first == -1 && ma[x].second == -1) return 0;
        ll tem1 = LLONG_MAX / 2, tem2 = LLONG_MAX / 2;
        if (ma[x].first != -1) {
            tem1 = cnt[x].second + 1LL * abs(sz[x].second - (sz[x].first - 1));
            tem1 += dfs2(ma[x].first);
        }
        if (ma[x].second != -1) {
            tem2 = cnt[x].first + 1LL * abs(sz[x].second - 1 - sz[x].first);
            tem2 += dfs2(ma[x].second);
        }
        return min(tem1, tem2);
    };
    cout << dfs2(0) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}