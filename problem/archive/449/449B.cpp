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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    vector<int> train;
    for (int i = 0; i < k; i++) {
        int v, w; cin >> v >> w;
        v--;
        e[0].emplace_back(v, -w);
        e[v].emplace_back(0, -w);
        train.emplace_back(v);
    }

    vector<long long> dist(n, 2e18);
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto [y, cost]: e[x]) {
            long long d = dist[x] + abs(cost);
            if (d < dist[y]) {
                dist[y] = d;
                pq.emplace(d, y);
            }
        }
    }

    vi vis(n, 0), deg(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto [v, w]: e[u]) {
            if (dist[u] + abs(w) == dist[v]) {
                if (u == 0 && w < 0) vis[v]++;
                deg[v]++;
            }
        }
    }

    int ans = 0;
    for (auto v: train) {
        if (!vis[v] || deg[v] > 1) {
            ans++;
            if (vis[v]) {
                vis[v]--;
                deg[v]--;
            }
        }
        else if (vis[v]) vis[v]--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}