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
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, n) in(a[i]);

    auto calc = [&] (ll x) -> ll {
        vector<vector<ll>> f(n, vector<ll>(m, LLONG_MAX));
        rep(i, n) {
            rep(j, m) {
                auto d = a[i][j] - (x + i + j);
                if (d < 0) continue;
                if (i == 0 && j == 0) {
                    f[i][j] = d;
                }
                else if (i == 0) {
                    if (f[i][j - 1] == LLONG_MAX) continue;
                    f[i][j] = f[i][j - 1] + d;
                }
                else if (j == 0) {
                    if (f[i - 1][j] == LLONG_MAX) continue;
                    f[i][j] = f[i - 1][j] + d;
                }
                else {
                    if (f[i][j - 1] == LLONG_MAX && f[i - 1][j] == LLONG_MAX) continue;
                    f[i][j] = min(f[i][j - 1], f[i - 1][j]) + d;
                }
            }
        }
        return f[n - 1][m - 1];
    };

    ll ans = LLONG_MAX;
    rep(i, n) {
        rep(j, m) {
            ans = min(ans, calc(a[i][j] - i - j));
        }
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