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
    vector<int> ori;
    int x;
    while (cin >> x) {
        ori.push_back(x);
    }
    int temp = ori.size() / 2;
    vector<int> in(ori.begin(), ori.begin() + temp);
    vector<int> post(ori.begin() + temp, ori.end());
    vector<int> pre;
    function<void(vector<int>&, vector<int>&)> dfs = [&](vector<int>& in, vector<int>& post) {
        if (in.size() == 0) return;
        if (in.size() == 1) {
            pre.push_back(in[0]);
            return;
        }
        int idx = -1;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == post[in.size() - 1]) {
                idx = i;
                break;
            }
        }
        vector<int> in1(in.begin(), in.begin() + idx);
        vector<int> in2(in.begin() + idx + 1, in.end());
        vector<int> po1(post.begin(), post.begin() + idx);
        vector<int> po2(post.begin() + idx, post.end() - 1);
        pre.push_back(in[idx]);
        dfs(in1, po1);
        dfs(in2, po2);
        return;
    };
    dfs(in, post);
    for (int p : pre) cout << p << ' ';
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}