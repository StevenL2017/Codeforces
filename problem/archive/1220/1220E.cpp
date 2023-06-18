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
    int n, m; cin >> n >> m;
    vi a(n); in(a);
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int s; cin >> s;
    s--;

    ll tot = 0, mx = 0;
    vector<ll> vis(n), d(n, 0), w(n, 0);
    function<void(int, int)> dfs = [&] (int u, int p) {
        vis[u] = 1;
        for (auto v : e[u]) {
            if (v == p) continue;
            if (vis[v]) {
                d[u]++;
            } else {
                dfs(v, u);
                d[u] += d[v];
                w[u] = max(w[u], w[v]);
            }
        }
        w[u] += a[u];
        if (d[u]) {
            tot += a[u];
        } else {
            mx = max(mx, w[u]);
        }
    };
    dfs(s, -1);

    cout << tot + mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}