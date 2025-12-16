#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, p, r;
    cin >> n;
    vector<vector<pair<int, int>>> ma(n);
    vector<vector<int>> ma2(n, vector<int>(n, 0));
    unordered_map<string, int> s;
    vector<string> ss(n);
    string x, y;
    int z;
    for (int i = 0; i <= n - 1; i++) {
        cin >> x;
        s[x] = i;
        ss[i] = x;
    }
    cin >> p;
    for (int i = 0; i <= p - 1; i++) {
        cin >> x >> y >> z;
        ma[s[x]].emplace_back(s[y], z);
        ma[s[y]].emplace_back(s[x], z);
        ma2[s[x]][s[y]] = z;
        ma2[s[y]][s[x]] = z;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    cin >> r;
    string st, fi;
    for (int i = 0; i <= r - 1; i++) {
        cin >> st >> fi;
        if (st == fi) {
            cout << st << endl;
            continue;
        }
        vector<ll> dis(n, LLONG_MAX / 2);
        vector<int> pre(n);
        dis[s[st]] = 0;
        q.emplace(0, s[st]);
        while (!q.empty()) {
            auto [dis_x, x] = q.top();
            q.pop();
            if (dis_x > dis[x]) continue;
            for (auto [y, z] : ma[x]) {
                int dis_y = dis_x + z;
                if (dis_y < dis[y]) {
                    dis[y] = dis_y;
                    pre[y] = x;
                    q.emplace(dis_y, y);
                }
            }
        }
        vector<int> res;
        for (int i = s[fi]; i != s[st]; i = pre[i]) {
            res.push_back(i);
        }
        res.push_back(s[st]);
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size() - 1; i++) {
            if (i == 0)
                cout << ss[res[i]] << "->(" << ma2[res[i]][res[i + 1]] << ")->" << ss[res[i + 1]];
            else
                cout << "->(" << ma2[res[i]][res[i + 1]] << ")->" << ss[res[i + 1]];
        }
        cout << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}