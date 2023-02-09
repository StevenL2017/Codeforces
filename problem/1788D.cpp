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
const int MAXN = 3e3 + 3;

int fact[MAXN];
int inv_[MAXN];
int c[MAXN][MAXN];

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
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    precompute(n);

    int ans = 0;
    repa(i, 2, n + 1) {
        ans = add(ans, c[n][i]);
    }

    vi cnt(n + 1, 0);
    rep(i, n + 1) {
        repa(j, 4, n + 1) {
            cnt[i] = add(cnt[i], c[i][j - 4]);
        }
    }

    repa(i, 2, n - 1) {
        repa(j, 1, i) {
            int mid = a[i] - a[j];
            int left = lower_bound(a.begin(), a.end(), a[j] - mid) - a.begin() - 1;
            int right = lower_bound(a.begin(), a.end(), a[i] + mid) - a.begin();
            if (j - left - 1 > 0 && right - i - 1 > 0) {
                ans = add(ans, mul(mul(j - left - 1, right - i - 1), max(1, cnt[n - (right - left - 1)])));
            }
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