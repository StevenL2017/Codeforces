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
#define ssz(x) (int)((x).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

class UnionFind {
private:
    unordered_map<int, int> f;

public:
    int find(int x) {
        if (!f.count(x)) return f[x] = x;
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    bool merge(int x, int y) {
        int x_ = find(x), y_ = find(y);
        if (x_ == y_) return false;
        f[y_] = x_;
        return true;
    }
};

struct Edges {
    int u, v, w, fu, fv;
};

const int N = 5e5 + 3;

vi idx[N];

void solve() {
    int n, m; cin >> n >> m;
    vector<Edges> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u--; e[i].v--;
        idx[e[i].w].push_back(i);
    }

    UnionFind uf;
    for (int w = 0; w < N; w++) {
        for (auto i: idx[w]) {
            e[i].fu = uf.find(e[i].u);
            e[i].fv = uf.find(e[i].v);
        }
        for (auto i: idx[w]) {
            uf.merge(e[i].u, e[i].v);
        }
    }

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;

        bool ok = true;
        UnionFind temp;
        while (k--) {
            int x; cin >> x;
            x--;
            if (!ok || !temp.merge(e[x].fu, e[x].fv)) {
                ok = false;
                continue;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}