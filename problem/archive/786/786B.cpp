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

const int N = 3e5 + 3;

struct Node {
    int l = 0, r = 0, l_child = -1, r_child = -1;
};

int tot;
Node a[N];
vector<pair<int, int>> e[N];

int new_node(int l, int r) {
    if (l == r) {
        return l;
    }
    a[tot] = {l, r, -1, -1};
    return tot++;
}

void build(int root) {
    if (a[root].l == a[root].r) {
        return;
    }
    int m = a[root].l + (a[root].r - a[root].l) / 2;
    a[root].l_child = new_node(a[root].l, m);
    a[root].r_child = new_node(m + 1, a[root].r);
    build(a[root].l_child);
    build(a[root].r_child);
}

void link(int u, int v, int w) {
    e[u].emplace_back(v, w);
}

void update(int root, int l, int r, int v, int w, int op) {
    if (a[root].l >= l && a[root].r <= r) {
        if (op == 2) {
            link(v, root, w);
        } else {
            link(root, v, w);
        }
        return;
    }
    if (a[root].l > r || a[root].r < l) {
        return;
    }
    update(a[root].l_child, l, r, v, w, op);
    update(a[root].r_child, l, r, v, w, op);
}

vector<long long> dijkstra(int n, int start) {
    vector<long long> dist(n, 2e18);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (cost > dist[x]) continue;
        for (auto& [y, w]: e[x]) {
            long long d = dist[x] + w;
            if (d < dist[y]) {
                dist[y] = d;
                pq.emplace(d, y);
            }
        }
    }
    return dist;
}

void solve() {
    int n, q, s;
    cin >> n >> q >> s;
    s--;

    tot = n;
    rep(i, n) {
        a[i].l = a[i].r = i;
    }

    int root1 = new_node(0, n - 1);
    build(root1);
    int root2 = new_node(0, n - 1);
    build(root2);
    repa(i, n, 2 * n - 1) {
        link(i, a[i].l_child, 0);
        link(i, a[i].r_child, 0);
    }
    repa(i, 2 * n - 1, 3 * n - 2) {
        link(a[i].l_child, i, 0);
        link(a[i].r_child, i, 0);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int v, u, w;
            cin >> v >> u >> w;
            v--; u--;
            link(v, u, w);
        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            v--; l--; r--;
            int root = (op == 2 ? root1 : root2);
            update(root, l, r, v, w, op);
        }
    }

    auto d = dijkstra(tot, s);
    rep(i, n) cout << (d[i] < 2e18 ? d[i] : -1) << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}