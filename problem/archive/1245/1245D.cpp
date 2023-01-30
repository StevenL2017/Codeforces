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
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;
    vi c(n), k(n); in(c); in(k);

    ll ans = 0;
    vi station, vis(n, 0), parent(n, -1);
    vector<pair<int, int>> conn;
    rep(_, n) {
        ll mn = LLONG_MAX;
        int u = -1;
        rep(i, n) {
            if (vis[i]) continue;
            if (c[i] < mn) {
                mn = c[i];
                u = i;
            }
        }

        ans += mn;
        if (parent[u] == -1) {
            station.push_back(u + 1);
        } else {
            conn.emplace_back(parent[u] + 1, u + 1);
        }
        vis[u] = 1;

        rep(i, n) {
            if (vis[i]) continue;
            ll cost = (abs(p[i].first - p[u].first) + abs(p[i].second - p[u].second)) * 1ll * (k[i] + k[u]);
            if (cost < c[i]) {
                c[i] = cost;
                parent[i] = u;
            }
        }
    }

    cout << ans << endl;
    cout << ssz(station) << endl;
    out(station);
    cout << ssz(conn) << endl;
    for (auto& [fi, se]: conn) {
        cout << fi << " " << se << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}