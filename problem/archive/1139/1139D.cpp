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

const int MOD = 1e9 + 7;

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

void solve() {
    int m; cin >> m;

    vector<bool> is_prime(m + 1, true);
    vector<map<int, int>> primes(m + 1);
    for (int i = 2; i <= m; i++) {
        if (!is_prime[i]) continue;
        for (int j = i; j <= m; j += i) {
            int x = j, cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            is_prime[j] = false;
            primes[j][i] = cnt;
        }
    }

    vector<vi> factors(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            factors[j].push_back(i);
        }
    }

    auto calc = [&] (int x, int fac) -> int {
        vi a;
        for (auto [k, v] : primes[x]) {
            if (!primes[fac].count(k) || v != primes[fac][k]) {
                a.push_back(k);
            }
        }

        int cnt = m / fac;
        int n = ssz(a);
        for (int i = 1; i < (1 << n); i++) {
            int sign = 1, prod = 1;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    sign *= -1;
                    prod = mul(prod, a[j]);
                }
            }
            cnt = add(cnt, sign * (m / fac / prod));
        }
        return cnt;
    };

    vi f(m + 1, 0);
    for (int i = 2; i <= m; i++) {
        int rhs = 1;
        for (auto fac : factors[i]) {
            auto cnt = calc(i, fac);
            rhs = add(rhs, divide(mul(f[fac], cnt), m));
        }
        auto cnt = m / i;
        f[i] = divide(mul(rhs, m), m - cnt);
    }

    int ans = 1;
    for (int i = 1; i <= m; i++) {
        ans = add(ans, divide(f[i], m));
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