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

int m, d, a[N], vis[N];
vector<int> e[N], e1[N];

void dfs1(int u, int color, int idx) {
    if (vis[u] || a[u] != color) return;
    vis[u] = idx;
    for (auto v : e[u]) {
        dfs1(v, color, idx);
    }
}

int dfs2(int u, int p) {
    int cur = 0;
    for (auto v : e1[u]) {
        if (v == p) continue;
        int t = dfs2(v, u) + 1;
        d = max(d, cur + t);
        cur = max(cur, t);
    }
    return cur;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        if (vis[u]) continue;
        dfs1(u, a[u], ++m);
    }

    for (int u = 1; u <= n; u++) {
        for (auto v : e[u]) {
            if (vis[u] != vis[v]) {
                e1[vis[u]].push_back(vis[v]);
            }
        }
    }
    dfs2(1, 0);

    cout << (d + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}