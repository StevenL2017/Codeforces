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
const int MAXN = 1e1 + 3;

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
    string s1, s2;
    cin >> s1 >> s2;

    get_factorial();

    int cnt1 = 0, cnt2 = 0, c = 0;
    for (int i = 0; i < ssz(s1); i++) {
        cnt1 += (s1[i] == '+' ? 1 : -1);
        if (s2[i] == '?') c++;
        else cnt2 += (s2[i] == '+' ? 1 : -1);
    }

    int d = abs(cnt1 - cnt2);
    if (d > c || (d & 1) != (c & 1)) {
        cout << 0 << endl;
        return;
    }

    int k = (c - d) / 2;
    long double ans = comb(c, k);
    for (int i = 0; i < c; i++) {
        ans *= 0.5;
    }

    cout.precision(16);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}