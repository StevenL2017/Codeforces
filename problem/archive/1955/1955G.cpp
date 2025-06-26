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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    vector<vi> f(n, vi(m));
    auto check = [&] (int x) -> bool {
        for (int i = 0; i < n; i++) {
            f[i].assign(m, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] % x) {
                    continue;
                }
                if (i == 0 && j == 0) {
                    f[i][j] = 1;
                }
                if (i > 0) {
                    f[i][j] |= f[i - 1][j];
                }
                if (j > 0) {
                    f[i][j] |= f[i][j - 1];
                }
            }
        }
        return (f[n - 1][m - 1] ? true : false);
    };

    int g = gcd(a[0][0], a[n - 1][m - 1]), x = 1;
    int ans = 0;
    while (x * x <= g) {
        if (g % x == 0) {
            if (check(x)) {
                ans = max(ans, x);
            }
            if (x * x < g && check(g / x)) {
                ans = max(ans, g / x);
            }
        }
        x++;
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