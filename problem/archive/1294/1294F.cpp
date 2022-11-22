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
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int a = -1, d1 = -1;
    function<void(int, int, int)> dfs1 = [&] (int node, int fa, int d) {
        if (d > d1) {
            d1 = d;
            a = node;
        }
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs1(nxt, node, d + 1);
        }
    };
    dfs1(0, -1, 0);

    int b = -1, d2 = -1;

    int t = 0;
    vector<int> parent(n), depth(n);
    vector<int> tin(n), tout(n);
    
    function<void(int, int, int)> dfs2 = [&] (int node, int fa, int d) {
        if (d > d2) {
            d2 = d;
            b = node;
        }
        parent[node] = fa;
        depth[node] = d;
        tin[node] = t++;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs2(nxt, node, d + 1);
        }
        tout[node] = t++;
    };

    function<bool(int, int)> is_parent = [&] (int node, int target) -> bool {
        return tin[node] <= tin[target] && tout[target] <= tout[node];
    };

    dfs2(a, -1, 0);

    int c = -1, d3 = -1;
    function<void(int, int, int)> dfs3 = [&] (int node, int fa, int d) {
        if (!is_parent(node, b) && depth[node] - d > d3) {
            d3 = depth[node] - d;
            c = node;
        }
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            if (is_parent(node, b)) dfs3(nxt, node, depth[node]);
            else dfs3(nxt, node, d);
        }
    };
    dfs3(a, -1, 0);

    if (c == -1) {
        d3 = 0;
        rep(i, n) {
            if (i != a && i != b) {
                c = i;
                break;
            }
        }
    }

    cout << d2 + d3 << endl;
    cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}