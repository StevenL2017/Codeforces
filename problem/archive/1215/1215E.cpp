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
    vi a(n); in(a);

    vector<vi> color(20);
    rep(i, n) {
        color[a[i] - 1].push_back(i);
    }

    vector<vector<ll>> cnt(20, vector<ll>(20, 0));
    rep(i, 20) {
        rep(j, 20) {
            if (i == j || color[i].empty() || color[j].empty()) continue;
            for (int p1 = 0, p2 = 0; p1 < ssz(color[i]); p1++) {
                while (p2 + 1 < ssz(color[j]) && color[j][p2 + 1] < color[i][p1]) {
                    p2++;
                }
                if (color[j][p2] < color[i][p1]) {
                    cnt[i][j] += p2 + 1;
                }
            }
        }
    }

    int m = 1 << 20;
    vector<ll> f(m, 1e18);
    f[0] = 0;
    rep(mask, m) {
        rep(i, 20) {
            if (mask >> i & 1) continue;
            ll c = 0;
            rep(j, 20) {
                if (mask >> j & 1) {
                    c += cnt[j][i];
                }
            }
            f[mask | (1 << i)] = min(f[mask | (1 << i)], f[mask] + c);
        }
    }

    cout << f.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}