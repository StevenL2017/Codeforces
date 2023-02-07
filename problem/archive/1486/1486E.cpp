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

vector<int> dijkstra(int n, vector<vector<int>> edges, vector<vector<int>> weights, int start) {
    vector<int> dist(n, INT_MAX), dist_mid(n * 51, INT_MAX);
    dist[start] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, start, 0);
    while (!pq.empty()) {
        auto [cost, node, mid] = pq.top();
        pq.pop();
        if (mid == 0 && dist[node] < cost) continue;
        if (mid > 0 && dist_mid[node * 50 + mid] < cost) continue;
        for (int i = 0; i < ssz(edges[node]); i++) {
            int nxt = edges[node][i], w = weights[node][i];
            if (mid == 0 && cost < dist_mid[nxt * 50 + w]) {
                dist_mid[nxt * 50 + w] = cost;
                pq.emplace(dist_mid[nxt * 50 + w], nxt, w);
            }
            if (mid > 0 && cost + (mid + w) * (mid + w) < dist[nxt]) {
                dist[nxt] = cost + (mid + w) * (mid + w);
                pq.emplace(dist[nxt], nxt, 0);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> e(n), weight(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }

    auto ans = dijkstra(n, e, weight, 0);
    rep(i, n) {
        if (ans[i] == INT_MAX) {
            ans[i] = -1;
        }
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}