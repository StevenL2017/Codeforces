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

const int MAXN = 2e5 + 3;

// 路径压缩 + 启发式合并
class UnionFind {
private:
    int N;
    int *f;
    int *sz;
    int count;

public:
    UnionFind(int n) :
        N(n), count(n) {
        f = new int[N]();
        sz = new int[N]();
        for (int i = 0; i < N; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }
    
    ~UnionFind() {
        delete[] f;
        delete[] sz;
    }

    int find(int x) {
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    bool merge(int x, int y) {
        int x_ = find(x), y_ = find(y);
        if (x_ == y_) return false;
        if (sz[x_] < sz[y_]) {
            int temp = y_; y_ = x_; x_ = temp;
        }
        f[y_] = x_;
        sz[x_] += sz[y_];
        count--;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int u, v, w, i;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

// 建图（树）
vector<int> graph[MAXN];
vector<int> weight[MAXN];

// Kruskal算法
int mst_edges[MAXN];
long long kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    long long value = 0;
    for (auto& [u, v, w, i]: edges) {
        if (!uf.same(u, v)) {
            uf.merge(u, v);
            value += w;
            mst_edges[i] = 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
    }
    return value;
}

// 深度 depth，祖先 f，代价 cost
int depth[MAXN];
int f[MAXN][31];
int cost[MAXN][31];

// 用来为 lca_max 算法做准备，编号 1 ~ n
void dfs_max(int node, int fa) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1
    f[node][0] = fa;
    depth[node] = depth[f[node][0]] + 1;
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点
    for (int i = 1; i < 31; i++) {
        f[node][i] = f[f[node][i - 1]][i - 1];
        cost[node][i] = max(cost[f[node][i - 1]][i - 1], cost[node][i - 1]);
    }
    // 遍历子节点来进行 dfs
    int sz = graph[node].size();
    for (int i = 0; i < sz; i++) {
        if (graph[node][i] == fa) continue;
        cost[graph[node][i]][0] = weight[node][i];
        dfs_max(graph[node][i], node);
    }
}

// 用倍增算法算 x 和 y 之间的边权最大值
int lca_max(int x, int y) {
    // 令 y 比 x 深
    if (depth[x] > depth[y]) swap(x, y);
    // 令 y 和 x 在一个深度
    int tmp = depth[y] - depth[x], ans = 0;
    for (int j = 0; tmp; j++, tmp >>= 1) {
        if (tmp & 1) ans = max(ans, cost[y][j]), y = f[y][j];
    }
    // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先
    if (y == x) return ans;
    // 不然的话，找到第一个不是它们祖先的两个点
    for (int j = 30; j >= 0 && y != x; j--) {
        if (f[x][j] != f[y][j]) {
            ans = max({ans, cost[x][j], cost[y][j]});
            x = f[x][j];
            y = f[y][j];
        }
    }
    // 返回结果
    ans = max({ans, cost[x][0], cost[y][0]});
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    auto s = kruskal(n + 1, edges);

    memset(depth, 0, sizeof(depth));
    memset(f, 0, sizeof(f));
    memset(cost, 0, sizeof(cost));
    dfs_max(1, 0);

    rep(i, m) {
        if (mst_edges[i]) cout << s << endl;
        else cout << s + edges[i].w - lca_max(edges[i].u, edges[i].v) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}