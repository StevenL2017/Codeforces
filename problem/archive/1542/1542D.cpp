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

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    int n; cin >> n;
    vi a(n + 1, 0);
    rep(i, n) {
        char op; cin >> op;
        if (op == '+') {
            cin >> a[i + 1];
        }
    }

    int ans = 0;
    repa(k, 1, n + 1) {
        if (a[k] == 0) continue;
        vector<vi> f(n + 2, vi(n + 2, 0));
        f[0][0] = 1;
        repa(i, 1, n + 1) {
            rep(j, i + 1) {
                if (a[i] == 0) {
                    if (i <= k || j > 0) {
                        f[i][max(j - 1, 0)] = add(f[i][max(j - 1, 0)], f[i - 1][j]);
                    }
                } else {
                    if (a[i] < a[k] || a[i] == a[k] && i < k) {
                        f[i][j + 1] = add(f[i][j + 1], f[i - 1][j]);
                    } else {
                        f[i][j] = add(f[i][j], f[i - 1][j]);
                    }
                }
                if (i != k) {
                    f[i][j] = add(f[i][j], f[i - 1][j]);
                }
            }
        }
        rep(i, n + 1) {
            ans = add(ans, mul(f[n][i], a[k]));
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