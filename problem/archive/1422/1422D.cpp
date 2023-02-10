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

void solve() {
    int n, m; cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    vector<pair<int, int>> p(m);
    vector<pair<int, int>> a(m), b(m);
    rep(i, m) {
        int x, y; cin >> x >> y;
        p[i] = {x, y};
        a[i] = {x, i};
        b[i] = {y, i};
    }

    vector<vector<pair<int, int>>> e(m);
    for (auto &s: vector{a, b}) {
        sorta(s);
        rep(i, m - 1) {
            int u = s[i].second, v = s[i + 1].second;
            int x1 = p[u].first, y1 = p[u].second;
            int x2 = p[v].first, y2 = p[v].second;
            int d = min(abs(x1 - x2), abs(y1 - y2));
            e[u].emplace_back(v, d);
            e[v].emplace_back(u, d);
        }
    }

    vector<int> dist(m, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    rep(i, m) {
        dist[i] = min(abs(sx - p[i].first), abs(sy - p[i].second));
        pq.emplace(dist[i], i);
    }
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto &[y, cost]: e[x]) {
            auto d = dist[x] + cost;
            if (d < dist[y]) {
                dist[y] = d;
                pq.emplace(d, y);
            }
        }
    }

    int ans = abs(fx - sx) + abs(fy - sy);
    rep(i, m) {
        ans = min(ans, dist[i] + abs(fx - p[i].first) + abs(fy - p[i].second));
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