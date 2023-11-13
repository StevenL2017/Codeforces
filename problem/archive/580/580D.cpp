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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n); in(a);
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        e[x - 1].emplace_back(y - 1, c);
    }

    vector<vector<ll>> f(1 << n, vector<ll>(n, 0));
    for (int j = 0; j < n; j++) {
        f[1 << j][j] = a[j];
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!(i >> j & 1)) continue;
            for (auto [y, c]: e[j]) {
                if (i >> y & 1) continue;
                f[i | (1 << y)][y] = max(f[i | (1 << y)][y], f[i][j] + a[y] + c);
            }
            for (int y = 0; y < n; y++) {
                if (i >> y & 1) continue;
                f[i | (1 << y)][y] = max(f[i | (1 << y)][y], f[i][j] + a[y]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != m) continue;
        for (int j = 0; j < n; j++) {
            ans = max(ans, f[i][j]);
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