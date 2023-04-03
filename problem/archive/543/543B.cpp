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

vi dijkstra(int n, vector<vector<int>> e, int start) {
    vi dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first, x = t.second;
        if (dist[x] < cost) continue;
        for (auto& y: e[x]) {
            auto d = dist[x] + 1;
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
    vector<vi> e(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int s1, t1, l1;
    cin >> s1 >> t1 >> l1;
    s1--; t1--;
    int s2, t2, l2;
    cin >> s2 >> t2 >> l2;
    s2--; t2--;

    vector<vi> d(n);
    rep(i, n) {
        d[i] = dijkstra(n, e, i);
    }

    if (d[s1][t1] > l1 || d[s2][t2] > l2) {
        cout << -1 << endl;
        return;
    }

    int mn = d[s1][t1] + d[s2][t2];
    rep(i, n) {
        rep(j, n) {
            if (d[s1][i] + d[i][j] + d[j][t1] > l1 && d[s1][j] + d[j][i] + d[i][t1] > l1) continue;
            if (d[s2][i] + d[i][j] + d[j][t2] > l2 && d[s2][j] + d[j][i] + d[i][t2] > l2) continue;
            mn = min(mn, d[s1][i] + d[j][t1] + d[i][j] + d[s2][i] + d[j][t2]);
            mn = min(mn, d[s1][i] + d[j][t1] + d[i][j] + d[s2][j] + d[i][t2]);
        }
    }

    cout << m - mn << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}