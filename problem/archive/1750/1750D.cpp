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

const int MOD = 998244353;

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

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] % a[i + 1] != 0) {
            cout << 0 << endl;
            return;
        }
        int r = a[i] / a[i + 1], x = 2;
        int cur = m / a[i + 1], tot = 0;
        vi primes;
        while (x * x <= r) {
            if (r % x == 0) {
                primes.push_back(x);
                while (r % x == 0) {
                    r /= x;
                }
            }
            x++;
        }
        if (r > 1) {
            primes.push_back(r);
        }
        for (int mask = 0; mask < 1 << ssz(primes); mask++) {
            int prod = 1, cnt = 0;
            for (int i = 0; i < ssz(primes); i++) {
                if (mask >> i & 1) {
                    prod *= primes[i];
                    cnt++;
                }
            }
            if (cnt % 2 == 0) {
                tot += cur / prod;
            } else {
                tot -= cur / prod;
            }
        }
        ans = mul(ans, tot);
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