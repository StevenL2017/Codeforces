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
    vector<vector<pair<int, int>>> e(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
        edges.emplace_back(u, v);
    }
    int start;
    cin >> start;
    start--;

    vi parent(n, -1);
    vector<long long> dist(n, 2e18), weight(n);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        ll cost = t.first;
        int x = t.second;
        if (dist[x] < cost) continue;
        for (auto& [y, w]: e[x]) {
            long long d = dist[x] + w;
            if (d < dist[y]) {
                parent[y] = x;
                weight[y] = w;
                dist[y] = d;
                pq.emplace(d, y);
            } else if (d == dist[y] && w < weight[y]) {
                parent[y] = x;
                weight[y] = w;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += weight[i];
    }
    cout << ans << endl;
    for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (parent[u] == v || parent[v] == u) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}