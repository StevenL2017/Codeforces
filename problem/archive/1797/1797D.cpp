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
    int n, m; cin >> n >> m;
    vector<ll> a(n); in(a);
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi sz(n), fa(n);
    vector<ll> cost(n);
    vector<set<pair<int, int>>> sons(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        sz[u] = 1;
        fa[u] = p;
        cost[u] = a[u];
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            cost[u] += cost[v];
            sons[u].insert(make_pair(-sz[v], v));
        }
    };
    dfs(0, -1);

    while (m--) {
        int op, x; cin >> op >> x;
        x--;
        if (op == 1) {
            cout << cost[x] << endl;
        } else {
            if (sons[x].empty()) continue;
            auto f = fa[x];
            auto [_, v] = *sons[x].begin();
            sons[f].erase(make_pair(-sz[x], x));
            sons[x].erase(make_pair(-sz[v], v));
            sz[x] -= sz[v];
            sz[v] += sz[x];
            fa[x] = v;
            fa[v] = f;
            cost[x] -= cost[v];
            cost[v] += cost[x];
            sons[v].insert(make_pair(-sz[x], x));
            sons[f].insert(make_pair(-sz[v], v));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}