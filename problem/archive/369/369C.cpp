#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    vi f(n);
    function<int(int, int, int)> dfs = [&] (int u, int p, int t) -> int {
        int cur = (t == 1 ? -1 : u);
        for (auto [v, w]: e[u]) {
            if (v == p) continue;
            auto nxt = dfs(v, u, w);
            if (nxt != -1 && f[nxt]) cur = nxt;
        }
        if (cur != -1) {
            f[cur] = 1;
        }
        return cur;
    };
    dfs(0, -1, 1);

    vi ans;
    for (int i = 0; i < n; i++) {
        if (f[i]) ans.emplace_back(i + 1);
    }
    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}