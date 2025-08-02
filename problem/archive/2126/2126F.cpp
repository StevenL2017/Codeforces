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
    int n, q;
    cin >> n >> q;
    vi a(n);
    in(a);
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    ll ans = 0;
    vector<pair<int, int>> par(n);
    vector<map<int, ll>> cnt(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        par[u].first = p;
        for (auto [v, w]: e[u]) {
            if (v == p) {
                continue;
            }
            if (a[u] != a[v]) {
                ans += w;
            }
            dfs(v, u);
            par[v].second = w;
            cnt[u][a[v]] += w;
        }
    };
    dfs(0, -1);

    while (q--) {
        int u, x;
        cin >> u >> x;
        u--;

        if (par[u].first != -1) {
            if (a[par[u].first] == a[u]) {
                ans += par[u].second;
            }
            if (a[par[u].first] == x) {
                ans -= par[u].second;
            }
            cnt[par[u].first][a[u]] -= par[u].second;
            cnt[par[u].first][x] += par[u].second;
        }
        ans += cnt[u][a[u]];
        ans -= cnt[u][x];
        a[u] = x;

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}