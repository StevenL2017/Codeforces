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
    vi a(n); in(a);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi sz(n, 0);
    vector<ll> f(n, 0);
    function<void(int, int)> dfs = [&] (int u, int p) {
        sz[u] = 1;
        for (auto v : e[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
        }
        if (p != -1) {
            f[p] += f[u] + sz[u] * 1ll * (a[u] ^ a[p]);
        }
    };
    dfs(0, -1);

    vector<ll> ans(n, 0);
    function<void(int, int)> reroot = [&] (int u, int p) {
        ans[u] = f[u];
        for (auto v : e[u]) {
            if (v == p) continue;
            f[u] -= f[v] + sz[v] * 1ll * (a[u] ^ a[v]);
            sz[u] -= sz[v];
            f[v] += f[u] + sz[u] * 1ll * (a[u] ^ a[v]);
            sz[v] += sz[u];
            reroot(v, u);
            sz[v] -= sz[u];
            f[v] -= f[u] + sz[u] * 1ll * (a[u] ^ a[v]);
            sz[u] += sz[v];
            f[u] += f[v] + sz[v] * 1ll * (a[u] ^ a[v]);
        }
    };
    reroot(0, -1);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}