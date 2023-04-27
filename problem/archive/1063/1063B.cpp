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
    int n, m; cin >> n >> m;
    int sr, sc; cin >> sr >> sc;
    sr--; sc--;
    int x, y; cin >> x >> y;
    vector<string> a(n); in(a);

    deque<pair<int, int>> q;
    q.emplace_back(sr, sc);
    vector<vi> dist(n, vi(m, 1e9));
    dist[sr][sc] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop_front();
        for (auto& [dr, dc]: dirs4) {
            auto nr = r + dr, nc = c + dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < m && a[nr][nc] == '.') {
                auto cost = (dc == -1 ? 1: 0);
                if (dist[nr][nc] > dist[r][c] + cost) {
                    dist[nr][nc] = dist[r][c] + cost;
                    if (cost) {
                        q.emplace_back(nr, nc);
                    } else {
                        q.emplace_front(nr, nc);
                    }
                }
            }
        }
    }

    int ans = 0;
    rep(r, n) {
        rep(c, m) {
            if (dist[r][c] == 1e9) continue;
            auto left = dist[r][c];
            auto right = c - sc + left;
            ans += (left <= x && right <= y);
        }
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