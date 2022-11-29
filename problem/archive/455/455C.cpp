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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> graph(n);
    UnionFind uf(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        uf.merge(u, v);
    }

    vi p(n, 0);
    vi used(n, 0);
    vector<int> d1(n), d2(n);
    rep(i, n) {
        auto o = uf.find(i);
        if (!used[o]) {
            used[o] = 1;

            // calculate diameter of tree
            int d = 0;
            function<void(int, int)> diameter = [&] (int node, int fa) {
                d1[node] = d2[node] = 0;
                for (auto& nxt: graph[node]) {
                    if (nxt == fa) continue;
                    diameter(nxt, node);
                    int t = d1[nxt] + 1;
                    if (t > d1[node]) {
                        d2[node] = d1[node];
                        d1[node] = t;
                    }
                    else if (t > d2[node]) {
                        d2[node] = t;
                    }
                }
                d = max(d, d1[node] + d2[node]);
            };
            
            diameter(o, -1);
            p[o] = d;
        }
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            x--;
            cout << p[uf.find(x)] << endl;
        } else {
            int x, y; cin >> x >> y;
            x--; y--;
            if (uf.same(x, y)) continue;
            auto p1 = p[uf.find(x)], p2 = p[uf.find(y)];
            auto p3 = max({p1, p2, (p1 + 1) / 2 + (p2 + 1) / 2 + 1});
            uf.merge(x, y);
            p[uf.find(x)] = p3;
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