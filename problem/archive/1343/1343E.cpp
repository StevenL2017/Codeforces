#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
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

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
// const int INF = 2e9 + 7;
const long long INF = 9e18 + 7;

vector<long long> dijkstra(int n, vector<vector<pair<int, int>>> g, int start) {
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
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
                pq.emplace(d, y);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--; b--; c--;
    vi p(m); in(p);
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v, 1);
        g[v].emplace_back(u, 1);
    }

    auto da = dijkstra(n, g, a);
    auto db = dijkstra(n, g, b);
    auto dc = dijkstra(n, g, c);
    
    sorta(p);
    vector<ll> pre(m + 1, 0);
    rep(i, m) {
        pre[i + 1] = pre[i] + p[i];
    }

    ll ans = INF;
    rep(i, n) {
        auto cnt1 = da[i] + dc[i];
        auto cnt2 = db[i];
        if (cnt1 + cnt2 > m) continue;
        ans = min(ans, pre[cnt2] + pre[cnt1 + cnt2]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}