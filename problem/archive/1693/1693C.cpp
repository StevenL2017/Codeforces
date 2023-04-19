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
    vector<vi> e(n);
    vi deg(n, 0);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[v].push_back(u);
        deg[u]++;
    }

    vi dist(n, INT_MAX);
    dist[n - 1] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(0, n - 1);
    while (!q.empty()) {
        auto [cost, u] = q.top();
        q.pop();
        if (-cost > dist[u]) continue;
        for (auto& v: e[u]) {
            if (dist[u] + deg[v] < dist[v]) {
                dist[v] = dist[u] + deg[v];
                q.emplace(-dist[v], v);
            }
            deg[v]--;
        }
    }

    cout << dist[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}