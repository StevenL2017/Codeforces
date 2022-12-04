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

vector<int> dijkstra(int n, vector<vector<int>> g, int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto& y: g[x]) {
            long long d = dist[x] + 1;
            if (d < dist[y]) {
                dist[y] = d;
                pq.emplace(d, y);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> g(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    auto d = dijkstra(n, g, 0);
    vi d1(n, n), vis(n, 0);
    function<void(int)> dfs = [&] (int node) {
        vis[node] = 1;
        for (auto& nxt: g[node]) {
            if (d[node] < d[nxt]) {
                if (!vis[nxt]) dfs(nxt);
                d1[node] = min(d1[node], d1[nxt]);
            } else {
                d1[node] = min(d1[node], d[nxt]);
            }
        }
    };
    dfs(0);

    vi ans(n);
    rep(i, n) {
        ans[i] = min({d[i], d1[i]});
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}