#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
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

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int t = 0;
    vi parent(n), depth(n);
    vi tin(n), tout(n);
    function<void(int, int, int)> dfs = [&] (int node, int fa, int d) {
        parent[node] = fa;
        depth[node] = d;
        tin[node] = t++;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs(nxt, node, d + 1);
        }
        tout[node] = t++;
    };
    dfs(0, -1, 0);

    function<bool(int, int)> is_parent = [&] (int node, int target) -> bool {
        return tin[node] <= tin[target] && tout[target] <= tout[node];
    };

    while (m--) {
        int k; cin >> k;
        vi v(k);
        rep(i, k) {
            cin >> v[i];
            v[i]--;
        }

        int deepest = v[0];
        for (auto& node: v) {
            if (depth[node] > depth[deepest]) deepest = node;
        }
        for (auto& node: v) {
            if (node != deepest && parent[node] != -1) node = parent[node];
        }

        bool ok = true;
        for (auto& node: v) {
            if (!is_parent(node, deepest)) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}