#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n, tot;
double get_distance(int x_1, int y_1, int x_2, int y_2) { return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2)); }
void solve() {
    tot++;
    cout << "Scenario #" << tot << endl;
    cout << "Frog Distance = ";
    int x, y;
    vector<pair<int, int>> m;
    for (int i = 0; i <= n - 1; i++) {
        cin >> x >> y;
        m.emplace_back(x, y);
    }
    vector<vector<pair<int, double>>> ma(n);
    vector<double> dis(n, 1e18);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> q;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {
            if (i == j) continue;
            double temp = get_distance(m[i].first, m[i].second, m[j].first, m[j].second);
            ma[i].emplace_back(j, temp);
            ma[j].emplace_back(i, temp);
        }
    }
    q.emplace(0, 0);
    dis[0] = 0;
    while (!q.empty()) {
        auto [d, x] = q.top();
        q.pop();
        if (d > dis[x]) continue;
        for (auto& [y, z] : ma[x]) {
            double dis_y = max(d, z);
            if (dis_y < dis[y]) {
                dis[y] = dis_y;
                q.emplace(dis_y, y);
            }
        }
    }
    printf("%.3lf\n", dis[1]);
    cout << endl;
    return;
}
int main() {
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
    system("pause");
    return 0;
}