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

const int MOD = 1e9 + 7;
const int N = 1e5 + 3;

vi e[N];

int dfn[N], low[N], dfncnt, s[N], in_stack[N], tp;
int scc[N], sc;  // 结点 i 所在 SCC 的编号
int sz[N];       // 强连通 i 的大小

void tarjan_scc(int u) {
    if (dfn[u]) return;
    low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan_scc(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
        while (s[tp] != u) {
            scc[s[tp]] = sc;
            sz[sc]++;
            in_stack[s[tp]] = 0;
            --tp;
        }
        scc[s[tp]] = sc;
        sz[sc]++;
        in_stack[s[tp]] = 0;
        --tp;
    }
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        tarjan_scc(i);
    }

    vector<pair<int, int>> f(sc + 1, {INT_MAX, 0});
    for (int i = 1; i <= n; i++) {
        if (f[scc[i]].first > a[i - 1]) {
            f[scc[i]].first = a[i - 1];
            f[scc[i]].second = 1;
        }
        else if (f[scc[i]].first == a[i - 1]) {
            f[scc[i]].second += 1;
        }
    }

    ll ans = 0;
    int cnt = 1;
    for (int i = 1; i <= sc; i++) {
        ans += f[i].first;
        cnt = (cnt * 1ll * f[i].second) % MOD;
    }

    cout << ans << " " << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}