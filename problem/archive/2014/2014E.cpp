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

const long long INF = 1e18;

vector<long long> dijkstra(int n, vector<vector<pair<int, int>>>& edges, int start, vi& horses) {
    vector<long long> dist(n * 2, INF);
    dist[start] = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.emplace(0, start, 0);
    while (!pq.empty()) {
        auto [cost, x, h] = pq.top();
        pq.pop();
        if (dist[x + h * n] < cost) continue;
        for (auto& [y, w]: edges[x]) {
            int nh = h | horses[x];
            long long d = dist[x + h * n] + (nh ? w / 2 : w);
            if (d < dist[y + nh * n]) {
                dist[y + nh * n] = d;
                pq.emplace(d, y, nh);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vi a(n);
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        x--;
        a[x] = 1;
    }
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    auto d1 = dijkstra(n, e, 0, a);
    auto d2 = dijkstra(n, e, n - 1, a);

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, max(min(d1[i], d1[i + n]), min(d2[i], d2[i + n])));
    }
    cout << (ans < INF ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}