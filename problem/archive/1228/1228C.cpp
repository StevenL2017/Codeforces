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

ll mul(ll x, ll y) {
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y) {
    ll z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

void solve() {
    ll x, n;
    cin >> x >> n;

    set<ll> primes;
    int i = 2;
    while (i * i <= x) {
        if (x % i == 0) {
            primes.insert(i);
            while (x % i == 0) {
                x /= i;
            }
        }
        i++;
    }
    if (x > 1) primes.insert(x);

    ll ans = 1;
    for (auto p: primes) {
        ll cur = 1, cnt = 0;
        while (cur <= n / p) {
            cur *= p;
            cnt += n / cur;
        }
        ans = mul(ans, binpow(p, cnt));
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