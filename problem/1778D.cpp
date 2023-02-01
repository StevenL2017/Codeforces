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
    int n; cin >> n;
    string a, b; cin >> a >> b;

    int m = 0;
    rep(i, n) {
        if (a[i] != b[i]) {
            m++;
        }
    }

    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    vector<ll> p(n + 1, 1), q(n + 1, 1);
    repd(i, n - 1, 0) {
        p[i] = n * q[i + 1] + (n - i) * p[i + 1];
        q[i] = i * q[i + 1];
        p[i] %= MOD;
        q[i] %= MOD;
    }

    ll x = p[1], y = q[1];
    repa(i, 2, m + 1) {
        ll nx = x * q[i] + y * p[i];
        ll ny = y * q[i];
        nx %= MOD;
        ny %= MOD;
        x = nx;
        y = ny;
    }

    cout << divide(x, y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}