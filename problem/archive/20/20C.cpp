#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

pair<vector<long long>, vector<long long>> dijkstra(int n, vector<vector<int>> edges) {
    vector<vector<pair<int, int>>> g(n);
    for (auto& edge: edges) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
        g[edge[1]].emplace_back(edge[0], edge[2]);
    }

    vector<long long> dist(n, INF), path(n);
    int start = 0;
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto& [y, cost]: g[x]) {
            long long d = dist[x] + cost;
            if (d < dist[y]) {
                dist[y] = d;
                path[y] = x;
                pq.emplace(d, y);
            }
        }
    }
    return {dist, path};
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> edges(m, vi(3));
    rep(i, m) {
        rep(j, 3) {
            cin >> edges[i][j];
            if (j < 2) {
                edges[i][j]--;
            }
        }
    }

    auto ans = dijkstra(n, edges);
    if (ans.first[n - 1] == INF) {
        cout << -1 << endl;
    } else {
        auto path = ans.second;
        vi p;
        int i = n - 1;
        while (i != 0) {
            p.push_back(i);
            i = path[i];
        }
        p.push_back(0);
        reverse(p.begin(), p.end());
        for (auto& x: p) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}