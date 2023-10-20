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
    int n, m, d;
    cin >> n >> m >> d;
    vi vis(n, 0);
    for (int i = 0; i < m; i++) {
        int u; cin >> u;
        u--;
        vis[u] = 1;
    }
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi down(n, -1);
    function<void(int, int)> dfs1 = [&] (int u, int p) {
        for (auto v: e[u]) {
            if (v == p) continue;
            dfs1(v, u);
            if (down[v] != -1) {
                down[u] = max(down[u], down[v] + 1);
            }
        }
        if (vis[u]) down[u] = max(down[u], 0);
    };
    dfs1(0, -1);

    vi up(n, -1);
    function<void(int, int)> dfs2 = [&] (int u, int p) {
        int mx1 = -1, mx2 = -1;
        for (auto v: e[u]) {
            if (v == p) continue;
            if (mx1 < down[v]) {
                mx2 = mx1;
                mx1 = down[v];
            } else if (mx2 < down[v]) {
                mx2 = down[v];
            }
        }
        for (auto v: e[u]) {
            if (v == p) continue;
            if (down[v] == mx1) {
                if (mx2 != -1) up[v] = max(up[v], mx2 + 2);
            } else {
                if (mx1 != -1) up[v] = max(up[v], mx1 + 2);
            }
            if (up[u] != -1) up[v] = max(up[v], up[u] + 1);
            if (vis[v]) up[v] = max(up[v], 0);
            dfs2(v, u);
        }
    };
    up[0] = vis[0] ? 0 : -1;
    dfs2(0, -1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (down[i] <= d && up[i] <= d) {
            ans++;
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