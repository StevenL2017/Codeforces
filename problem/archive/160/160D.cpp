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

struct Edge {
    int u, v, w, i;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

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

const int MAXN = 1e5 + 3;

vector<int> e[MAXN];
// dfn：记录每个点的时间戳
// low：能不经过父亲到达最小的编号
// tt：时间戳
int dfn[MAXN], low[MAXN], tt;

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    rep(i, m) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
        edges[i].i = i;
    }

    vi ans(m, 0), idx(m), vis(m, 0);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return edges[i] < edges[j]; });
    UnionFind uf(n);
    for (int i = 0, j = 0; i < m; ) {
        while (j < m && edges[idx[j]].w == edges[idx[i]].w) {
            j++;
        }

        repa(k, i, j) {
            int u = edges[idx[k]].u, v = edges[idx[k]].v;
            int fu = uf.find(u), fv = uf.find(v);
            e[fu].clear();
            e[fv].clear();
            dfn[fu] = dfn[fv] = 0;
        }
        repa(k, i, j) {
            int u = edges[idx[k]].u, v = edges[idx[k]].v;
            int fu = uf.find(u), fv = uf.find(v);
            if (fu != fv) {
                e[fu].emplace_back(idx[k]);
                e[fv].emplace_back(idx[k]);
                ans[idx[k]] = 2;
            }
        }

        tt = 0;
        function<void(int)> tarjan_edge = [&] (int u) {
            low[u] = dfn[u] = ++tt;
            for (auto ei: e[u]) {
                if (vis[ei]) continue;
                vis[ei] = 1;
                auto v = uf.find(edges[ei].u) + uf.find(edges[ei].v) - u;
                v = uf.find(v);
                if (dfn[v] == 0) {
                    tarjan_edge(v);
                    low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
                    if (low[v] > dfn[u]) {
                        ans[ei] = 1;
                    }
                } else {
                    low[u] = min(low[u], dfn[v]); // 更新能到的最小节点编号
                }
            }
        };
        repa(k, i, j) {
            int u = edges[idx[k]].u, v = edges[idx[k]].v;
            int fu = uf.find(u), fv = uf.find(v);
            if (dfn[fu] == 0) {
                tarjan_edge(fu);
            }
            if (dfn[fv] == 0) {
                tarjan_edge(fv);
            }
        }

        repa(k, i, j) {
            int u = edges[idx[k]].u, v = edges[idx[k]].v;
            uf.merge(u, v);
        }
        i = j;
    }

    vector<string> desc = {"none", "any", "at least one"};
    rep(i, m) {
        cout << desc[ans[i]] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}