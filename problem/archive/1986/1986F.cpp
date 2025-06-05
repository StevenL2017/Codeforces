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

const int N = 2e5 + 3;

vector<vi> e(N);
// dfn：记录每个点的时间戳
// low：能不经过父亲到达最小的编号
// tt：时间戳
int dfn[N], low[N], tt;
// bridge: 割边答案
set<pair<int, int>> bridge;

void tarjan_edge(int u, int p, int n) {
    low[u] = dfn[u] = ++tt;
    for (auto v: e[u]) {
        if (v == p) continue;
        if (dfn[v] == 0) {
            tarjan_edge(v, u, n);
            low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
            if (low[v] > dfn[u]) {
                bridge.emplace(u, v);
            }
        } else {
            low[u] = min(low[u], dfn[v]); // 更新能到的最小节点编号
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        e[i].clear();
        dfn[i] = 0;
        low[i] = 0;
    }
    tt = 0;
    bridge.clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    tarjan_edge(0, -1, n);

    vi sz(n);
    function<void(int)> dfs = [&] (int u) {
        sz[u] = 1;
        for (auto v: e[u]) {
            if (sz[v]) {
                continue;
            }
            dfs(v);
            sz[u] += sz[v];
        }
    };
    dfs(0);

    ll ans = 0;
    for (auto [u, v]: bridge) {
        int c = min(sz[u], sz[v]);
        ans = max(ans, c * 1ll * (n - c));
    }
    cout << n * 1ll * (n - 1) / 2 - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}