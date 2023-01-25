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
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    rep(i, n) in(a[i]);

    UnionFind uf(n * m);
    rep(i, n) {
        map<int, int> mp;
        rep(j, m) {
            if (mp.count(a[i][j])) {
                uf.merge(i * m + j, mp[a[i][j]]);
            }
            mp[a[i][j]] = i * m + j;
        }
    }
    rep(j, m) {
        map<int, int> mp;
        rep(i, n) {
            if (mp.count(a[i][j])) {
                uf.merge(i * m + j, mp[a[i][j]]);
            }
            mp[a[i][j]] = i * m + j;
        }
    }

    vector<vi> e(n * m);
    vi deg(n * m, 0);
    rep(i, n) {
        vector<pair<int, int>> vp;
        rep(j, m) {
            vp.emplace_back(a[i][j], j);
        }
        sorta(vp);
        rep(k, ssz(vp) - 1) {
            if (vp[k].first != vp[k + 1].first) {
                auto u = uf.find(i * m + vp[k].second);
                auto v = uf.find(i * m + vp[k + 1].second);
                e[u].push_back(v);
                deg[v]++;
            }
        }
    }
    rep(j, m) {
        vector<pair<int, int>> vp;
        rep(i, n) {
            vp.emplace_back(a[i][j], i);
        }
        sorta(vp);
        rep(k, ssz(vp) - 1) {
            if (vp[k].first != vp[k + 1].first) {
                auto u = uf.find(vp[k].second * m + j);
                auto v = uf.find(vp[k + 1].second * m + j);
                e[u].push_back(v);
                deg[v]++;
            }
        }
    }

    queue<int> q;
    vi rank(n * m, 1);
    rep(i, n) {
        rep(j, m) {
            if (uf.find(i * m + j) == i * m + j && deg[i * m + j] == 0) {
                q.push(i * m + j);
            }
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto& v: e[u]) {
            rank[v] = max(rank[v], rank[u] + 1);
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<vi> ans(n, vi(m, 1));
    rep(i, n) {
        rep(j, m) {
            ans[i][j] = rank[uf.find(i * m + j)];
        }
    }
    rep(i, n) out(ans[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}