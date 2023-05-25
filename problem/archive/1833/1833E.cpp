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

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<set<int>> e(n);
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        int u = i, v = a[i] - 1;
        e[u].insert(v);
        e[v].insert(u);
        uf.merge(u, v);
    }

    set<int> s;
    vi cnt(n, 3);
    for (int i = 0; i < n; i++) {
        if (uf.sz[uf.find(i)] >= 2) {
            s.insert(uf.find(i));
            cnt[uf.find(i)] = min(cnt[uf.find(i)], ssz(e[i]));
        }
    }

    int mx = ssz(s), mn = 0;
    for (auto v : s) {
        if (cnt[v] == 2) {
            mn++;
        }
    }
    if (mx > mn) mn++;

    cout << mn << " " << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}