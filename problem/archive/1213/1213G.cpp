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

struct Edge {
    int u, v, w, i;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

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
    int n, m;
    cin >> n >> m;
    vector<Edge> e;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e.emplace_back(Edge{u, v, w, i});
    }
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(e.begin(), e.end());
    sort(q.begin(), q.end());

    vector<ll> ans(m);
    UnionFind uf(n);
    ll s = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n - 1 && e[j].w <= q[i].first) {
            s += uf.sz[uf.find(e[j].u)] * 1ll * uf.sz[uf.find(e[j].v)];
            uf.merge(e[j].u, e[j].v);
            j++;
        }
        ans[q[i].second] = s;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}