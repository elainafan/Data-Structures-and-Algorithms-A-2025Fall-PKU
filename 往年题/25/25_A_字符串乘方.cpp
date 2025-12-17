#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve()
{
    string s;
    while (cin >> s)
    {
        if (s == ".")
            return;
        int n = s.length();
        vector<int> pi(n);
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            char b = s[i];
            while (cnt && s[cnt] != b)
                cnt = pi[cnt - 1];
            if (s[cnt] == b)
                cnt++;
            pi[i] = cnt;
        }
        int lps = n - pi[n - 1];
        if (n % lps == 0)
            cout << n / lps << endl;
        else
            cout << 1 << endl;
    }
    return;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}