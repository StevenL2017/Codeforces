#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int tt = 0;
    vector<int> parent(n), tin(n), tout(n);
    set<int> s;
    function<void(int, int)> dfs = [&] (int node, int fa) {
        parent[node] = fa;
        tin[node] = ++tt;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs(nxt, node);
        }
        tout[node] = tt;
        if (tin[node] == tout[node]) {
            s.insert(tin[node]);
        }
    };
    dfs(0, -1);

    function<bool(int)> is_empty = [&] (int node) -> bool {
        auto it = s.lower_bound(tin[node]);
        return it != s.end() && *it <= tout[node];
    };

    function<void(int)> add = [&] (int node) {
        if (parent[node] != -1 && is_empty(parent[node])) {
            s.insert(tin[parent[node]]);
        }
        s.erase(s.lower_bound(tin[node]), s.upper_bound(tout[node]));
    };

    function<void(int)> remove = [&] (int node) {
        s.insert(tin[node]);
    };

    int q; cin >> q;
    while (q--) {
        int t, v; cin >> t >> v;
        v--;
        if (t == 1) {
            add(v);
        } else if (t == 2) {
            remove(v);
        } else {
            if (is_empty(v)) cout << 0 << endl;
            else cout << 1 << endl;
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