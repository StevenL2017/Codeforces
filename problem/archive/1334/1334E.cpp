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
const int MAXN = 1e2 + 3;

int factorial[MAXN];

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x) {
    return binpow(x, MOD - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}

void get_factorial() {
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++) factorial[i] = mul(i, factorial[i - 1]);
}

void solve() {
    ll D; cin >> D;

    vector<ll> primes;
    for (ll i = 2; i * i <= D; i++) {
        if (D % i == 0) {
            primes.push_back(i);
            while (D % i == 0) {
                D /= i;
            }
        }
    }
    if (D > 1) primes.push_back(D);

    get_factorial();

    int q; cin >> q;
    while (q--) {
        ll x, y; cin >> x >> y;

        ll left_tot = 0, right_tot = 0;
        vector<ll> left, right;
        for (auto& p: primes) {
            int cnt = 0;
            while (x % p == 0) {
                cnt--;
                x /= p;
            }
            while (y % p == 0) {
                cnt++;
                y /= p;
            }
            if (cnt < 0) {
                left_tot += -cnt;
                left.push_back(-cnt);
            } else {
                right_tot += cnt;
                right.push_back(cnt);
            }
        }

        int ans = 1;
        ans = mul(ans, factorial[left_tot]);
        ans = mul(ans, factorial[right_tot]);
        for (auto& c: left) {
            ans = divide(ans, factorial[c]);
        }
        for (auto& c: right) {
            ans = divide(ans, factorial[c]);
        }

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}