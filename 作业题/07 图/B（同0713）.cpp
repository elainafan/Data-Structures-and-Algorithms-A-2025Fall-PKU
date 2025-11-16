#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int p, q, r, ds;
void solve() {
    unordered_map<string, int> fa;
    unordered_map<int, string> fa2;
    string temp, temp2;
    cin >> p;
    for (int i = 1; i <= p; i++) {
        cin >> temp;
        fa[temp] = i - 1;
        fa2[i - 1] = temp;
    }
    vector<vector<pair<int, int>>> ma(p);
    vector<vector<int>> ma2(p, vector<int>(p, INT_MAX));
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> temp >> temp2 >> ds;
        ma[fa[temp]].emplace_back(fa[temp2], ds);
        ma[fa[temp2]].emplace_back(fa[temp], ds);
        ma2[fa[temp]][fa[temp2]] = ds;
        ma2[fa[temp2]][fa[temp]] = ds;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    cin >> r;
    for (int i = 1; i <= r; i++) {
        cin >> temp >> temp2;
        int s = fa[temp], f = fa[temp2];
        if (s == f) {
            cout << temp << endl;
            continue;
        }
        vector<int> dis(p, INT_MAX);
        vector<vector<int>> tem(p);
        dis[s] = 0;
        q.emplace(0, s);
        tem[s].push_back(s);
        while (!q.empty()) {
            auto [d, x] = q.top();
            q.pop();
            if (d > dis[x]) continue;
            for (auto& [y, z] : ma[x]) {
                int dis_y = d + z;
                if (dis_y < dis[y]) {
                    dis[y] = dis_y;
                    tem[y] = tem[x];
                    tem[y].push_back(y);
                    q.emplace(dis_y, y);
                }
            }
        }
        for (int j = 0; j < tem[f].size(); j++) {
            if (j == tem[f].size() - 1)
                cout << fa2[tem[f][j]] << endl;
            else
                cout << fa2[tem[f][j]] << "->(" << ma2[tem[f][j]][tem[f][j + 1]] << ")->";
        }
    }
    return;
}
int main() {
    solve();
    system("pause");
    return 0;
}