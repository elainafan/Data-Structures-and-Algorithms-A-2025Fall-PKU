#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n, m;
int toposort(int n, vector<vector<int>>& ma, vector<int> deg, vector<int>& res, int ans) {
    priority_queue<int, vector<int>, greater<>> q;
    int cnt = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (deg[i] == 0) {
            cnt++;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int tem = q.size();
        cnt = max(cnt, tem);
        int node = q.top();
        q.pop();
        res.push_back(node);
        for (int p : ma[node]) {
            if (--deg[p] == 0) q.push(p);
        }
    }
    if (res.size() == ans && ans == n && cnt == 1) return 2;
    if (res.size() < ans) return 0;
    return 1;
}
void solve() {
    vector<vector<int>> ma(n);
    vector<int> deg(n, -1);
    vector<int> res;
    map<int, int> tot;
    int ans = 0;
    string temp;
    int flag = 0;
    for (int i = 1; i <= m; i++) {
        cin >> temp;
        if (flag == 1 || flag == 2) continue;
        res.clear();
        int x = temp[0] - 'A', y = temp[2] - 'A';
        if (!tot.count(x)) {
            tot[x] = 1;
            ans++;
        }
        if (!tot.count(y)) {
            tot[y] = 1;
            ans++;
        }
        if (x == y) {
            flag = 1;
            cout << "Inconsistency found after " << i << " relations." << endl;
            continue;
        }
        ma[x].push_back(y);
        if (deg[y] != -1)
            deg[y]++;
        else
            deg[y] = 1;
        if (deg[x] == -1) deg[x] = 0;
        int pd = toposort(n, ma, deg, res, ans);
        if (pd == 2) {
            flag = 2;
            cout << "Sorted sequence determined after " << i << " relations: ";
            for (auto p : res) cout << (char)(p + 'A');
            cout << '.' << endl;
        }
        if (pd == 0) {
            flag = 1;
            cout << "Inconsistency found after " << i << " relations." << endl;
        }
    }
    if (!flag) cout << "Sorted sequence cannot be determined." << endl;
    return;
}
int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve();
    }
    system("pause");
    return 0;
}