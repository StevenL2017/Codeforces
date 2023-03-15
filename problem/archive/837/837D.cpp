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
    int n, k; cin >> n >> k;
    vector<ll> a(n); in(a);

    int c5 = 0;
    vector<pair<int, int>> cnt(n);
    rep(i, n) {
        ll x = a[i];
        cnt[i].first = cnt[i].second = 0;
        while (x % 2 == 0) {
            cnt[i].first++;
            x /= 2;
        }
        while (x % 5 == 0) {
            cnt[i].second++;
            x /= 5;
        }
        c5 += cnt[i].second;
    }
    
    vector<vi> f(k + 1, vi(c5 + 1, INT_MIN));
    f[0][0] = 0;
    rep(i, n) {
        vector<vi> g(k + 1, vi(c5 + 1, INT_MIN));
        rep(j, k + 1) {
            rep(c, c5 + 1) {
                g[j][c] = max(g[j][c], f[j][c]);
                if (j + 1 <= k && c + cnt[i].second <= c5) {
                    g[j + 1][c + cnt[i].second] = max(g[j + 1][c + cnt[i].second], f[j][c] + cnt[i].first);
                }
            }
        }
        f = g;
    }

    int ans = 0;
    rep(c, c5 + 1) {
        ans = max(ans, min(c, f[k][c]));
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