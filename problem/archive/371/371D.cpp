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
        // if (sz[x_] < sz[y_]) swap(x_, y_);
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
    vi a(n);
    in(a);

    UnionFind uf(n + 1);
    vi b(n);
    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            p = uf.find(p);
            while (p < n && x > 0) {
                int d = a[p] - b[p];
                if (x >= d) {
                    b[p] += d;
                    x -= d;
                    uf.merge(p + 1, p);
                    p = uf.find(p);
                } else {
                    b[p] += x;
                    x = 0;
                }
            }
        } else {
            int k;
            cin >> k;
            k--;
            cout << b[k] << endl;
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