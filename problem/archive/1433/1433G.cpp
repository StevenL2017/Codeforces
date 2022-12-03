#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>> g, int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto& [y, cost]: g[x]) {
            int d = dist[x] + cost;
            if (d < dist[y]) {
                dist[y] = d;
                pq.emplace(d, y);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n);
    map<pair<int, int>, int> weight;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        weight[{min(u, v), max(u, v)}] = w;
    }
    vector<pair<int, int>> route;
    rep(i, k) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        route.emplace_back(u, v);
    }

    vector<vector<int>> d(n);
    rep(i, n) {
        d[i] = dijkstra(n, graph, i);
    }

    int ans = INF;
    for (auto& [p, w]: weight) {
        int cur = 0;
        int x = p.first, y = p.second;
        rep(i, k) {
            int u = route[i].first, v = route[i].second;
            cur += min({d[u][v], d[u][x] + d[y][v], d[u][y] + d[x][v]});
        }
        ans = min(ans, cur);
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