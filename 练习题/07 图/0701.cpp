#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n;
int p, q;
int cnt = 0;
string ans = "";
bool pd = false;
int dx[9] = {0, -2, -2, -1, -1, 1, 1, 2, 2}, dy[9] = {0, -1, 1, -2, 2, -2, 2, -1, 1};
void dfs(int x, int y, int cnt, vector<vector<bool>>& vis) {
    vis[x][y] = true;
    if (cnt == p * q) {
        pd = true;
        cout << ans << endl;
        return;
    }
    for (int i = 1; i <= 8; i++) {
        int ax = x + dx[i], ay = y + dy[i];
        if (ax >= 0 && ax < p && ay >= 0 && ay < q && !vis[ax][ay]) {
            ans += (char)('A' + ax);
            ans += to_string(ay + 1);
            dfs(ax, ay, cnt + 1, vis);
            if (pd) return;
            ans.pop_back();
            if (!ans.empty() && isdigit(ans.back())) ans.pop_back();
            ans.pop_back();
        }
    }
    vis[x][y] = false;
    return;
}
int main() {
    cin >> n;
    while (n--) {
        cnt++;
        cout << "Scenario #" << cnt << ":" << endl;
        cin >> q >> p;
        vector<vector<bool>> vis(p, vector<bool>(q, false));
        pd = false;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                fill(vis.begin(), vis.end(), vector<bool>(q, false));
                ans = "";
                ans += (char)('A' + i);
                ans += to_string(j + 1);
                dfs(i, j, 1, vis);
                if (pd) break;
            }
            if (pd) break;
        }
        if (!pd) cout << "impossible" << endl;
        if (n != 0) cout << endl;
    }
    system("pause");
    return 0;
}