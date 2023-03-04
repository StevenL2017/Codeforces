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

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    int s = 0;
    rep(i, n) s += a[i];
    vector<vi> f(n + 1, vi(2 * s + 1, 0));
    f[0][s] = 1;
    int ans = 0;
    repa(i, 1, n + 1) {
        rep(j, 2 * s + 1) {
            if (j - a[i - 1] >= 0) {
                f[i][j] += f[i - 1][j - a[i - 1]];
                f[i][j] %= MOD;
            }
            if (j + a[i - 1] <= 2 * s) {
                f[i][j] += f[i - 1][j + a[i - 1]];
                f[i][j] %= MOD;
            }
        }
        ans += f[i][s];
        ans %= MOD;
        f[i][s]++;
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