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
    int n; cin >> n;
    vi a(n); in(a);

    UnionFind uf(n + 1);
    rep(i, n) {
        int v = i + 1 + a[i];
        if (v < 1 || v > n) v = 0;
        uf.merge(v, i + 1);
    }

    vi vis(n + 1, 0), s;
    int v = 1;
    bool ok = true;
    while (v >= 1 && v <= n) {
        if (vis[v]) {
            ok = false;
            break;
        }
        vis[v] = 1;
        s.push_back(v);
        v += a[v - 1];
    }

    ll ans = 0;
    int valid = uf.sz[uf.find(0)] - 1;
    if (ok) {
        map<int, int> cnt;
        repa(i, 1, n + 1) {
            if (uf.same(1, i)) {
                int v = i, c = 0;
                while (v >= 1 && v <= n && !vis[v]) {
                    c++;
                    v += a[v - 1];
                }
                if (v >= 1 && v <= n && vis[v]) {
                    cnt[v] += c;
                }
            }
        }
        rep(i, ssz(s)) {
            if (i > 0) cnt[s[i]] += cnt[s[i - 1]];
            cnt[s[i]]++;
        }
        repa(i, 1, n + 1) {
            if (!vis[i]) {
                ans += 2 * n + 1;
            } else {
                ans += valid + n + 1 - cnt[i];
            }
        }
    } else {
        repa(i, 1, n + 1) {
            if (vis[i]) {
                ans += valid + n + 1;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}