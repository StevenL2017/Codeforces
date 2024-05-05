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
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].emplace_back(v, 1);
        e[v].emplace_back(u, 0);
    }

    vi sz(n), d(n);
    function<void(int, int)> dfs1 = [&] (int u, int p) {
        for (auto [v, w] : e[u]) {
            if (v == p) continue;
            dfs1(v, u);
            sz[u] += sz[v] + 1;
            d[u] += d[v] + w;
        }
    };
    dfs1(0, -1);

    vi f(n);
    function<void(int, int)> dfs2 = [&] (int u, int p) {
        f[u] = sz[u] - d[u];
        for (auto [v, w] : e[u]) {
            if (v == p) continue;
            sz[u] -= sz[v] + 1;
            sz[v] += sz[u] + 1;
            d[u] -= d[v] + w;
            d[v] += d[u] + (w ^ 1);
            dfs2(v, u);
            d[v] -= d[u] + (w ^ 1);
            d[u] += d[v] + w;
            sz[v] -= sz[u] + 1;
            sz[u] += sz[v] + 1;
        }
    };
    dfs2(0, -1);

    int ans = n;
    vi cand;
    for (int i = 0; i < n; i++) {
        if (f[i] < ans) {
            ans = f[i];
            cand = {i + 1};
        }
        else if (f[i] == ans) {
            cand.push_back(i + 1);
        }
    }
    cout << ans << endl;
    out(cand);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}