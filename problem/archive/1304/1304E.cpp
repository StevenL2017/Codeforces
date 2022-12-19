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

const int MAXN = 1e5 + 3;

// 建图（树）
vector<int> graph[MAXN];
vector<int> weight[MAXN];

// 深度 depth，祖先 f，代价 cost
int depth[MAXN];
int f[MAXN][31];
int cost[MAXN][31];

// 用来为 lca_sum 算法做准备，编号 1 ~ n
void dfs_sum(int node, int fa) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1
    f[node][0] = fa;
    depth[node] = fa > 0 ? depth[f[node][0]] + 1 : 0;
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点
    for (int i = 1; i < 31; i++) {
        f[node][i] = f[f[node][i - 1]][i - 1];
        cost[node][i] = cost[f[node][i - 1]][i - 1] + cost[node][i - 1];
    }
    // 遍历子节点来进行 dfs
    int sz = graph[node].size();
    for (int i = 0; i < sz; i++) {
        if (graph[node][i] == fa) continue;
        cost[graph[node][i]][0] = weight[node][i];
        dfs_sum(graph[node][i], node);
    }
}

// 用倍增算法算 x 和 y 之间的边权和
int lca_sum(int x, int y) {
    // 令 y 比 x 深
    if (depth[x] > depth[y]) swap(x, y);
    // 令 y 和 x 在一个深度
    int tmp = depth[y] - depth[x], ans = 0;
    for (int j = 0; tmp; j++, tmp >>= 1) {
        if (tmp & 1) ans += cost[y][j], y = f[y][j];
    }
    // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先
    if (y == x) return ans;
    // 不然的话，找到第一个不是它们祖先的两个点
    for (int j = 30; j >= 0 && y != x; j--) {
        if (f[x][j] != f[y][j]) {
            ans += cost[x][j] + cost[y][j];
            x = f[x][j];
            y = f[y][j];
        }
    }
    // 返回结果
    ans += cost[x][0] + cost[y][0];
    return ans;
}

void solve() {
    int n; cin >> n;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        weight[u].push_back(1);
        weight[v].push_back(1);
    }
    dfs_sum(1, 0);

    int q; cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        int d1 = lca_sum(a, b);
        int d2 = lca_sum(a, x) + lca_sum(y, b) + 1;
        int d3 = lca_sum(a, y) + lca_sum(x, b) + 1;

        auto check = [&] (int d) -> bool {
            if (d <= k && (d & 1) == (k & 1)) return true;
            else return false;
        };

        if (check(d1) || check(d2) || check(d3)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}