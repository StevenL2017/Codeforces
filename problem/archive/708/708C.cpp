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
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi sz(n, 0);
    int center = -1;
    function<void(int, int)> dfs1 = [&] (int u, int p) {
        sz[u] = 1;
        int mx = 0;
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            mx = max(mx, sz[v]);
        }
        mx = max(mx, n - sz[u]);
        if (mx <= n / 2) {
            center = u;
        }
    };
    dfs1(0, -1);

    vi ans(n, 0);
    ans[center] = 1;
    dfs1(center, -1);

    vector<pair<int, int>> sub;
    for (auto& v: e[center]) {
        sub.emplace_back(sz[v], v);
    }
    sortd(sub);

    function<void(int, int, int, int)> dfs2 = [&] (int u, int p, int other, int f) {
        if (other <= n / 2) {
            ans[u] = 1;
        }
        rep(i, min(2, ssz(sub))) {
            if (sub[i].second == f) continue;
            if (n - (sz[u] + sub[i].first) <= n / 2) {
                ans[u] = 1;
                break;
            }
        }
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs2(v, u, other, f);
        }
    };
    for (auto& v: e[center]) {
        dfs2(v, center, n - sz[v], v);
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}