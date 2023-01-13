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

const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<vi> a(n, vi(m));
    rep(i, n) in(a[i]);

    auto dijkstra = [&] (int sr, int sc) -> vector<vector<int>> {
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[sr][sc] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, sr * m + sc);
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            auto cost = t.first;
            auto r = t.second / m, c = t.second % m;
            if (dist[r][c] < cost) continue;
            for (auto& dirs: dirs4) {
                auto nr = r + dirs[0], nc = c + dirs[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] == -1) continue;
                auto d = dist[r][c] + 1;
                if (d < dist[nr][nc]) {
                    dist[nr][nc] = d;
                    pq.emplace(d, nr * m + nc);
                }
            }
        }
        return dist;
    };

    auto d1 = dijkstra(0, 0), d2 = dijkstra(n - 1, m - 1);
    ll mn_end = 1e18;
    rep(i, n) {
        rep(j, m) {
            if (d2[i][j] < 1e9 && a[i][j] > 0) {
                mn_end = min(mn_end, w * 1ll * d2[i][j] + a[i][j]);
            }
        }
    }

    ll ans = d1[n - 1][m - 1] < 1e9 ? w * 1ll * d1[n - 1][m - 1] : 1e18;
    rep(i, n) {
        rep(j, m) {
            if (d1[i][j] < 1e9 && a[i][j] > 0) {
                ans = min(ans, w * 1ll * d1[i][j] + a[i][j] + mn_end);
            }
        }
    }

    cout << (ans < 1e18 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}