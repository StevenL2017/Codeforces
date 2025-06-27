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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<map<int, vi>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        g[u][c].push_back(v);
        g[v][c].push_back(u);
    }
    int b, e;
    cin >> b >> e;
    b--; e--;

    map<pair<int, int>, int> dist;
    deque<tuple<int, int, int>> q;
    q.emplace_back(0, b, 0);
    while (!q.empty()) {
        auto [d, u, c] = q.front();
        q.pop_front();
        if (dist.count({u, c})) {
            continue;
        }
        dist[{u, c}] = d;
        if (c) {
            q.emplace_front(d, u, 0);
            for (auto v: g[u][c]) {
                q.emplace_front(d, v, c);
            }
        } else {
            for (auto [c, _]: g[u]) {
                q.emplace_back(d + 1, u, c);
            }
        }
    }
    cout << dist[{e, 0}] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}