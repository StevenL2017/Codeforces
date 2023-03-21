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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vi a(n); in(a);
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<ll> sz(n, 0), f(n, 0);
    function<ll(int, int, int)> dfs1 = [&] (int u, int p, int d) -> ll {
        ll ans = d * 1ll * a[u];
        sz[u] = a[u];
        for (auto& v: e[u]) {
            if (v == p) continue;
            ans += dfs1(v, u, d + 1);
            sz[u] += sz[v];
        }
        return ans;
    };
    f[0] = dfs1(0, -1, 0);

    function<void(int, int)> dfs2 = [&] (int u, int p) {
        for (auto& v: e[u]) {
            if (v == p) continue;
            f[v] = f[u] - sz[v];
            sz[u] -= sz[v];
            f[v] += sz[u];
            sz[v] += sz[u];
            dfs2(v, u);
            sz[v] -= sz[u];
            sz[u] += sz[v];
        }
    };
    dfs2(0, -1);

    cout << *max_element(f.begin(), f.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}