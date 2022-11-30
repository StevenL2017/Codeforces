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

const int MAXN = 1e5 + 3;

vector<int> graph[MAXN];
int depth[MAXN], f[MAXN][31];
int tin[MAXN], tout[MAXN], sz[MAXN];
int tt = 0;

int dfs(int node, int fa) {
    f[node][0] = fa;
    depth[node] = fa > 0 ? depth[f[node][0]] + 1 : 0;
    tin[node] = tt++;
    for (int i = 1; i < 31; i++) {
        f[node][i] = f[f[node][i - 1]][i - 1];
    }
    int cnt = 1;
    for (int i = 0; i < ssz(graph[node]); i++) {
        if (graph[node][i] == fa) continue;
        cnt += dfs(graph[node][i], node);
    }
    tout[node] = tt;
    sz[node] = cnt;
    return cnt;
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    int tmp = depth[y] - depth[x];
    for (int j = 0; tmp; j++, tmp >>= 1) {
        if (tmp & 1) y = f[y][j];
    }
    if (y == x) return y;
    for (int j = 30; j >= 0 && y != x; j--) {
        if (f[x][j] != f[y][j]) {
            x = f[x][j];
            y = f[y][j];
        }
    }
    return y == x ? y : f[y][0];
}

int find_pth_parent(int x, int p) {
    for (int i = 0; i < 31; i++) {
        if (p >> i & 1) {
            x = f[x][i];
        }
    }
    return x;
}

bool is_parent(int node, int target) {
    return tin[node] <= tin[target] && tout[target] <= tout[node];
}

void solve() {
    int n; cin >> n;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);

    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << n << endl;
            continue;
        }
        if ((depth[x] + depth[y]) & 1) {
            cout << 0 << endl;
            continue;
        }
        if (depth[x] > depth[y]) swap(x, y);
        if (is_parent(x, y)) {
            auto p = (depth[y] - depth[x]) / 2;
            auto mid = find_pth_parent(y, p);
            auto mid1 = find_pth_parent(y, p - 1);
            cout << sz[mid] - sz[mid1] << endl;
        } else {
            auto o = lca(x, y);
            auto p = (depth[y] + depth[x]) / 2 - depth[o];
            auto mid = find_pth_parent(y, p);
            auto mid1 = find_pth_parent(y, p - 1);
            if (mid == o) {
                auto mid2 = find_pth_parent(x, p - 1);
                cout << n - sz[mid1] - sz[mid2] << endl;
            } else {
                cout << sz[mid] - sz[mid1] << endl;
            }
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