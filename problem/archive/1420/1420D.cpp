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
const int MAXN = 3e5 + 3;

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

int factorial[MAXN];

void get_factorial() {
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++) factorial[i] = mul(i, factorial[i - 1]);
}

int comb(int n, int k) {
    if (k > n) return 0;
    return divide(factorial[n], mul(factorial[n - k], factorial[k]));
}

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(2 * n);
    for (int i = 0; i < 2 * n; i += 2) {
        cin >> a[i].first >> a[i + 1].first;
        a[i].second = 1; a[i + 1].second = 2;
    }

    get_factorial();

    sorta(a);
    int ans = 0, cnt = 0;
    for (auto& [x, op]: a) {
        if (op == 1) {
            if (cnt >= k - 1) {
                ans = add(ans, comb(cnt, k - 1));
            }
            cnt++;
        } else {
            cnt--;
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