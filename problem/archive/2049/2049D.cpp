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
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    vector<vector<ll>> f(n + 1, vector<ll>(m, 9e18));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < m; c++) {
            vector<ll> g(m, 9e18);
            for (int j = 0; j < m; j++) {
                g[j] = min(g[j], f[i][j] + k * 1ll * c + a[i][(j + c) % m]);
            }
            for (int j = 0; j < m; j++) {
                g[j] = min(g[j], g[(j - 1 + m) % m] + a[i][(j + c) % m]);
            }
            for (int j = 0; j < m; j++) {
                f[i + 1][j] = min(f[i + 1][j], g[j]);
            }
        }
    }
    cout << f[n][m - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}