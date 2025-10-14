#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n;
int fa[26];
char s, d;
int m, z;
int get(int x) {
    if (fa[x] == x) return fa[x];
    return fa[x] = get(fa[x]);
}
void merge(int x, int y) {
    fa[get(x)] = get(y);
    return;
}
int main() {
    cin >> n;
    vector<tuple<int, int, int>> ma;
    for (int i = 0; i <= n - 1; i++) fa[i] = i;
    for (int i = 1; i <= n - 1; i++) {
        cin >> s >> m;
        for (int j = 1; j <= m; j++) {
            cin >> d >> z;
            ma.emplace_back(z, s - 'A', d - 'A');
        }
    }
    int ans = 0;
    sort(ma.begin(), ma.end());
    for (int i = 0; i < ma.size(); i++) {
        auto [z, x, y] = ma[i];
        int dx = get(x), dy = get(y);
        if (dx == dy) continue;
        ans += z;
        merge(x, y);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}