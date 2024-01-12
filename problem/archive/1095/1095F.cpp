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

struct Edge {
    ll u, v, w;
    Edge(ll u, ll v, ll w): u(u), v(v), w(w) {};
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    in(a);
    vector<Edge> edges;
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(Edge(u, v, w));
    }

    ll idx = 0, mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < mn) {
            idx = i;
            mn = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        edges.emplace_back(Edge(idx, i, mn + a[i]));
    }

    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    long long value = 0;
    for (auto& [u, v, w]: edges) {
        if (!uf.same(u, v)) {
            uf.merge(u, v);
            value += w;
        }
    }

    cout << value << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}