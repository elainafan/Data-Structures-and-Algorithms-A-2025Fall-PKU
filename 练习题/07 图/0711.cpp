#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n, tot;
void solve() {
    int m;
    string temp, temp2;
    double a;
    unordered_map<string, int> ma1;
    unordered_map<int, string> ma2;
    tot++;
    vector<vector<double>> ma(n, vector<double>(n, -1));
    for (int i = 0; i <= n - 1; i++) ma[i][i] = 1.0;
    cout << "Case " << tot << ": ";
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        ma1[temp] = i - 1;
        ma2[i - 1] = temp;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> temp >> a >> temp2;
        ma[ma1[temp]][ma1[temp2]] = a;
    }
    for (int k = 0; k <= n - 1; k++) {
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 1; j <= n - 1; j++) {
                ma[i][j] = max(ma[i][j], ma[i][k] * ma[k][j]);
            }
        }
    }
    bool pd = false;
    for (int i = 0; i <= n - 1; i++) {
        if (ma[i][i] > 1.0) pd = true;
    }
    if (pd)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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