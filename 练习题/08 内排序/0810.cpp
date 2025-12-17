#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    int x, y, z;
    vector<vector<int>> ma;
    for (int i = 0; i <= n - 1; i++) {
        cin >> x >> y >> z;
        ma.push_back({x, y, z});
    }
    vector<tuple<int, int, int>> ma2;
    function<int(int, int)> dis = [&](int x, int y) {
        return (ma[x][0] - ma[y][0]) * (ma[x][0] - ma[y][0]) + (ma[x][1] - ma[y][1]) * (ma[x][1] - ma[y][1]) +
               (ma[x][2] - ma[y][2]) * (ma[x][2] - ma[y][2]);
    };
    for (int i = 0; i <= n - 1; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            ma2.emplace_back(i, j, dis(i, j));
        }
    }
    sort(ma2.begin(), ma2.end(), [&](const tuple<int, int, int> &x, const tuple<int, int, int> &y) {
        auto [x1, y1, z1] = x;
        auto [x2, y2, z2] = y;
        if (z1 == z2) {
            if (x1 == x2) return y1 < y2;
            return x1 < x2;
        }
        return z1 > z2;
    });
    for (int i = 0; i <= ma2.size() - 1; i++) {
        auto [x, y, z] = ma2[i];
        cout << '(' << ma[x][0] << ',' << ma[x][1] << ',' << ma[x][2] << ')' << '-';
        cout << '(' << ma[y][0] << ',' << ma[y][1] << ',' << ma[y][2] << ')' << '=';
        cout << fixed << setprecision(2) << sqrt(z) << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}