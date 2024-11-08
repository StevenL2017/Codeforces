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
    int n, a, b;
    cin >> n >> a >> b;
    vi p(n);
    in(p);

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[p[i]] = i;
    }

    UnionFind uf(n);
    vi s(n);
    for (int i = 0; i < n; i++) {
        if (mp.count(a - p[i])) uf.merge(mp[a - p[i]], i), s[i] |= 1;
        if (mp.count(b - p[i])) uf.merge(mp[b - p[i]], i), s[i] |= 2;
    }

    vi t(n, 3);
    for (int i = 0; i < n; i++) {
        t[uf.find(i)] &= s[i];
    }

    for (int i = 0; i < n; i++) {
        if (t[uf.find(i)] == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    vi ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = (int)((t[uf.find(i)] & 1) == 0);
    }

    cout << "YES" << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}