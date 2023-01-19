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

int MOD;
const int MAXN = 403;

int fact[MAXN];
int inv_[MAXN];
int pow2[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int fastexp(int b, int exp) {
    if (exp == 0) return 1;
    int temp = fastexp(b, exp / 2);
    temp = mul(temp, temp);
    if (exp % 2 == 1) temp = mul(temp, b);
    return temp;
}

void precompute(int n) {
    fact[0] = 1;
    inv_[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv_[i] = fastexp(fact[i], MOD - 2);
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            c[i][j] = mul(mul(fact[i], inv_[j]), inv_[i - j]);
    for (int i = 0; i <= n; i++)
        pow2[i] = fastexp(2, i);
}

void solve() {
    int n; cin >> n >> MOD;

    precompute(n);
    f[0][0] = 1;
    rep(i, n) {
        rep(j, i + 1) {
            for (int k = 1; i + k <= n; k++) {
                f[i + k + 1][j + k] = add(f[i + k + 1][j + k], mul(mul(f[i][j], pow2[k - 1]), c[j + k][k]));
            }
        }
    }

    int ans = 0;
    rep(j, n + 1) ans = add(ans, f[n + 1][j]);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}