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
    int n; cin >> n;
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<vi> parent(n, vi(n, -1)), sz(n, vi(n, 0));
    function<void(int, int)> dfs = [&] (int u, int root) {
        sz[root][u] = 1;
        for (auto v : e[u]) {
            if (v == parent[root][u]) continue;
            parent[root][v] = u;
            dfs(v, root);
            sz[root][u] += sz[root][v];
        }
    };
    for (int i = 0; i < n; i++) {
        dfs(i, i);
    }

    vector<vector<ll>> f(n, vector<ll>(n, -1));
    function<ll(int, int)> dp = [&] (int u, int v) -> ll {
        if (u == v) return 0;
        if (f[u][v] != -1) return f[u][v];
        ll ans = sz[u][v] * 1ll * sz[v][u] + max(dp(u, parent[u][v]), dp(parent[v][u], v));
        return f[u][v] = ans;
    };

    ll ans = 0;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            ans = max(ans, dp(u, v));
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}