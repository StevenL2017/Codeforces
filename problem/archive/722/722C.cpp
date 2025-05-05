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

const int N = 1e5 + 1;

int a[N];

class UnionFind {
public:
    int N;
    int *f;
    ll *sz;
    int count;

    UnionFind(int n) :
        N(n), count(n) {
        f = new int[N]();
        sz = new ll[N]();
        for (int i = 0; i < N; i++) {
            f[i] = i;
            sz[i] = a[i];
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi p(n);
    in(p);

    UnionFind uf(n);
    vi vis(n);
    ll mx = 0;
    vector<ll> ans;
    for (int i = n - 1; i >= 0; i--) {
        ans.push_back(mx);
        int j = p[i] - 1;
        vis[j] = 1;
        if (j - 1 >= 0 && vis[j - 1]) {
            uf.merge(j - 1, j);
        }
        if (j + 1 < n && vis[j + 1]) {
            uf.merge(j, j + 1);
        }
        mx = max(mx, uf.sz[uf.find(j)]);
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}