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

const int MAXN = 1e5 + 3;

// 建图（树）
vector<int> graph[MAXN];

// 深度 depth，祖先 f
int depth[MAXN];
int f[MAXN][31];

// 用来为 lca 算法做准备，编号 1 ~ n
void dfs(int node, int fa) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1
    f[node][0] = fa;
    depth[node] = fa > 0 ? depth[f[node][0]] + 1 : 0;
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点
    for (int i = 1; i < 31; i++) {
        f[node][i] = f[f[node][i - 1]][i - 1];
    }
    // 遍历子节点来进行 dfs
    int sz = graph[node].size();
    for (int i = 0; i < sz; i++) {
        if (graph[node][i] == fa) continue;
        dfs(graph[node][i], node);
    }
}

// 用倍增算法算 x 和 y 的 lca 节点
int lca(int x, int y) {
    // 令 y 比 x 深
    if (depth[x] > depth[y]) swap(x, y);
    // 令 y 和 x 在一个深度
    int tmp = depth[y] - depth[x];
    for (int j = 0; tmp; j++, tmp >>= 1) {
        if (tmp & 1) y = f[y][j];
    }
    // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先
    if (y == x) return y;
    // 不然的话，找到第一个不是它们祖先的两个点
    for (int j = 30; j >= 0 && y != x; j--) {
        if (f[x][j] != f[y][j]) {
            x = f[x][j];
            y = f[y][j];
        }
    }
    // 返回结果
    return y == x ? y : f[y][0];
}

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> e(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }

    dfs(1, 0);

    vi cnt(n + 1, 0);
    int k; cin >> k;
    while (k--) {
        int u, v; cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        cnt[lca(u, v)] -= 2;
    }

    vi ans(n - 1, 0), sz(n + 1, 0);
    function<void(int, int)> dfs1 = [&] (int u, int p) {
        sz[u] = cnt[u];
        for (auto [v, i] : e[u]) {
            if (v == p) continue;
            dfs1(v, u);
            ans[i] += sz[v];
            sz[u] += sz[v];
        }
    };
    dfs1(1, 0);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}