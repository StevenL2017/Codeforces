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

const int MAXN = 3e5 + 3;

vector<pair<int, int>> e[MAXN];
// dfn：记录每个点的时间戳
// low：能不经过父亲到达最小的编号
// tt：时间戳
int dfn[MAXN], low[MAXN], tt;
// bridge: 割边答案
set<int> bridge;

// 因为 Tarjan 图不一定连通
// 遍历所有节点，所有未访问过的节点跑Tarjan
// tt = 0; 时间戳初始为 0
// tarjan_edge(i, -1); 从第 i 个点开始
void tarjan_edge(int u, int p) {
    low[u] = dfn[u] = ++tt;
    for (auto [v, i] : e[u]) {
        if (v == p) continue;
        if (dfn[v] == 0) {
            tarjan_edge(v, u);
            low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
            if (low[v] > dfn[u]) {
                bridge.insert(i);
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

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges.emplace_back(u, v);
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }

    tarjan_edge(0, -1);

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        if (bridge.count(i)) continue;
        uf.merge(edges[i].first, edges[i].second);
    }

    vector<set<int>> et(n);
    for (int i = 0; i < m; i++) {
        int u = uf.find(edges[i].first), v = uf.find(edges[i].second);
        if (u == v) continue;
        et[u].insert(v);
        et[v].insert(u);
    }

    int d = 0;
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        int cur = 0;
        for (auto v : et[u]) {
            if (v == p) continue;
            int nxt = dfs(v, u) + 1;
            d = max(d, cur + nxt);
            cur = max(cur, nxt);
        }
        return cur;
    };
    dfs(uf.find(0), -1);

    cout << d << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}