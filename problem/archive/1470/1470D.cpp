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
public:
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
    int n, m; cin >> n >> m;
    vector<vi> e(n);
    UnionFind uf(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        uf.merge(u, v);
    }

    if (uf.count > 1) {
        cout << "NO\n";
        return;
    }

    vi color(n, -1);
    color[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto& v: e[u]) {
            if (color[u] == 0) {
                color[v] = 1;
                q.push(v);
            } else {
                if (color[v] == -1) {
                    color[v] = 0;
                    q.push(v);
                }
            }
        }
    }

    vi ans;
    rep(i, n) {
        if (color[i] == 0) ans.push_back(i + 1);
    }

    cout << "YES\n" << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}