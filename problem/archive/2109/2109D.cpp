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

const ll INF = 1e18;

vector<vector<ll>> dijkstra(int n, vector<vector<int>> edges, int start) {
    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[start][0] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    pq.emplace(0, start, 0);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        auto [cost, x, op] = t;
        if (dist[x][op] < cost) continue;
        for (auto& y: edges[x]) {
            long long d = dist[x][op] + 1;
            if (d < dist[y][op ^ 1]) {
                dist[y][op ^ 1] = d;
                pq.emplace(d, y, op ^ 1);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vi a(l);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto d = dijkstra(n, e, 0);

    int mx1 = 0, mx2 = -1;
    for (auto x: a) {
        mx1 += x;
    }
    for (auto x: a) {
        if (mx1 % 2 != (mx1 - x) % 2) {
            mx2 = max(mx2, mx1 - x);
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i][mx1 & 1] <= mx1 || mx2 > -1 && d[i][mx2 & 1] <= mx2) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}