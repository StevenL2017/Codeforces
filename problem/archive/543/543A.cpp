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
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vi a(n); in(a);

    vector<vi> f(m + 1, vi(b + 1, 0));
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        vector<vi> g(m + 1, vi(b + 1, 0));
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                g[j][k] = f[j][k];
                if (j > 0 && k >= a[i]) {
                    g[j][k] += g[j - 1][k - a[i]];
                    g[j][k] %= mod;
                }
            }
        }
        f = g;
    }

    int ans = 0;
    for (int k = 0; k <= b; k++) {
        ans += f[m][k];
        ans %= mod;
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