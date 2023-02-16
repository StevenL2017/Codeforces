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
    int n, m, t;
    cin >> n >> m >> t;
    vector<vi> a(n, vi(m, 0));
    rep(i, n) {
        string s; cin >> s;
        rep(j, m) {
            if (s[j] == '1') {
                a[i][j] = 1;
            }
        }
    }

    vector<vi> f(n, vi(m, INT_MAX));
    rep(i, n) {
        rep(j, m) {
            if (i + 1 < n && a[i][j] == a[i + 1][j]) {
                f[i][j] = f[i + 1][j] = 0;
            }
            if (j + 1 < m && a[i][j] == a[i][j + 1]) {
                f[i][j] = f[i][j + 1] = 0;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    rep(i, n) {
        rep(j, m) {
            if (f[i][j] == 0) {
                q.emplace(i, j, 0);
            }
        }
    }
    while (!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();
        for (auto& [nr, nc]: vector<pair<int, int>>{{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}}) {
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && d + 1 < f[nr][nc]) {
                f[nr][nc] = d + 1;
                q.emplace(nr, nc, d + 1);
            }
        }
    }

    while (t--) {
        int i, j; ll p;
        cin >> i >> j >> p;
        i--; j--;

        if (f[i][j] == INT_MAX || p <= f[i][j]) {
            cout << a[i][j] << endl;
        } else {
            cout << (a[i][j] ^ ((p - f[i][j]) & 1)) << endl;
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