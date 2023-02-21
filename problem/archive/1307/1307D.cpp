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

vector<int> dijkstra(int n, vector<vector<int>> e, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto& y: e[x]) {
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
    int n, m, k;
    cin >> n >> m >> k;
    vi s(n, 0);
    rep(i, k) {
        int x; cin >> x;
        x--;
        s[x] = 1;
    }
    vector<vi> e(n);
    bool ok = false;
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        if (s[u] && s[v]) {
            ok = true;
        }
    }

    auto d = dijkstra(n, e, 0);
    if (ok) {
        cout << d[n - 1] << endl;
        return;
    }

    auto dr = dijkstra(n, e, n - 1);
    vector<pair<int, int>> diff;
    rep(i, n) {
        if (s[i]) {
            diff.emplace_back(d[i] - dr[i], i);
        }
    }
    sorta(diff);

    int ans = 0, mx = INT_MIN;
    for (auto& [_, i]: diff) {
        ans = max(ans, mx + dr[i] + 1);
        mx = max(mx, d[i]);
    }

    cout << min(d[n - 1], ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}