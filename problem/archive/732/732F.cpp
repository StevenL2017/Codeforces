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

const int MAXN = 4e5 + 3;
const int MAXM = 4e5 + 3;

pair<int, int> edges[MAXM];
vector<pair<int, int>> e1[MAXN], e2[MAXN], e3[MAXN];
// dfn：记录每个点的时间戳
// low：能不经过父亲到达最小的编号
// tt：时间戳
int dfn[MAXN], low[MAXN], tt;
// bridge: 割边答案
int bridge[MAXM];

// 因为 Tarjan 图不一定连通
// 遍历所有节点，所有未访问过的节点跑Tarjan
// tt = 0; 时间戳初始为 0
// tarjan_edge(i, -1); 从第 i 个点开始
void tarjan_edge(int u, int p) {
    low[u] = dfn[u] = ++tt;
    for (auto [v, i] : e1[u]) {
        if (v == p) continue;
        if (dfn[v] == 0) {
            tarjan_edge(v, u);
            low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
            if (low[v] > dfn[u]) {
                bridge[i] = 1;
            }
        } else {
            low[u] = min(low[u], dfn[v]); // 更新能到的最小节点编号
        }
    }
}

class UnionFind {
public:
    int N;
    int *f;
    int *sz;
    int count;
    
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
        if (sz[x_] < sz[y_]) swap(x_, y_);
        f[y_] = x_;
        sz[x_] += sz[y_];
        count--;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int vis[MAXM];
UnionFind uf(MAXN);

void dfs1(int u, int p) {
    for (auto [v, i] : e2[u]) {
        if (v == p || vis[i]) continue;
        vis[i] = 1;
        edges[i] = {u, v};
        uf.merge(u, v);
        dfs1(v, u);
    }
}

void dfs2(int u, int p) {
    for (auto [v, i] : e3[u]) {
        if (v == p) continue;
        auto [ori_u, ori_v] = edges[i];
        if (uf.find(ori_u) == u) {
            edges[i] = {ori_v, ori_u};
        } else {
            edges[i] = {ori_u, ori_v};
        }
        dfs2(v, u);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        e1[u].emplace_back(v, i);
        e1[v].emplace_back(u, i);
    }

    tarjan_edge(1, 0);
    for (int i = 0; i < m; i++) {
        if (bridge[i]) continue;
        auto [u, v] = edges[i];
        e2[u].emplace_back(v, i);
        e2[v].emplace_back(u, i);
    }

    int root = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        dfs1(i, 0);
        if (uf.sz[uf.find(i)] > mx) {
            mx = uf.sz[uf.find(i)];
            root = uf.find(i);
        }
    }

    for (int i = 0; i < m; i++) {
        if (bridge[i]) {
            auto [u, v] = edges[i];
            e3[uf.find(u)].emplace_back(uf.find(v), i);
            e3[uf.find(v)].emplace_back(uf.find(u), i);
        }
    }
    dfs2(root, 0);

    cout << mx << endl;
    for (int i = 0; i < m; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}