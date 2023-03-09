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

const long long INF = 1e18;

void solve() {
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;
    vector<vector<pair<int, int>>> e(n);
    vi w(m);
    rep(i, m) {
        int u, v;
        cin >> u >> v >> w[i];
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }

    int cnt = 0;
    vi idx(m);
    rep(i, m) {
        if (w[i] == 0) {
            idx[i] = cnt++;
        }
    }

    auto dijkstra = [&] (int s, int t, long long x) -> long long {
        vector<long long> dist(n, INF);
        dist[s] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (dist[u] < cost) continue;
            for (auto& [v, i]: e[u]) {
                long long d = dist[u] + (w[i] > 0 ? w[i] : (x + idx[i]) / cnt);
                if (d < dist[v]) {
                    dist[v] = d;
                    pq.emplace(d, v);
                }
            }
        }
        return dist[t];
    };

    if (dijkstra(s, t, (L + 1) * 1ll * cnt) < L) {
        cout << "NO\n";
        return;
    }
    if (dijkstra(s, t, 1ll * cnt) > L) {
        cout << "NO\n";
        return;
    }

    ll left = 1ll * cnt, right = (L + 1) * 1ll * cnt, ans = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (dijkstra(s, t, mid) <= L) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    rep(i, m) {
        if (w[i] == 0) {
            w[i] = (ans + idx[i]) / cnt;
        }
    }

    cout << "YES\n";
    rep(u, n) {
        for (auto& [v, i]: e[u]) {
            if (v > u) {
                cout << u << " " << v << " " << w[i] << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}