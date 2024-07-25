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

const int MAXN = 4e6 + 3;

struct Edge {
    int u, v, w, i;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

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
        }
    }
    return value;
}

void solve() {
    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    vector<Edge> e;
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            cout << "NO\n";
            return;
        }
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (a[i][j] != a[j][i] || a[i][j] == 0) {
                cout << "NO\n";
                return;
            }
            e.push_back(Edge({i, j, a[i][j], i * n + j}));
        }
    }
    kruskal(n, e);

    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = i * n + j;
            if (mst_edges[k]) {
                edges[i].emplace_back(j, a[i][j]);
                edges[j].emplace_back(i, a[i][j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        bool ok = true;
        function<void(int, int, ll)> dfs = [&] (int u, int p, ll s) {
            if (a[i][u] != s) {
                ok = false;
            }
            for (auto [v, w]: edges[u]) {
                if (v == p) continue;
                dfs(v, u, s + w);
            }
        };
        dfs(i, -1, 0);
        if (!ok) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}