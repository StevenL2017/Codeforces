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

void get_factorial(int n) {
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) factorial[i] = mul(i, factorial[i - 1]);
}

int comb(int n, int k) {
    if (k > n) return 0;
    return divide(factorial[n], mul(factorial[n - k], factorial[k]));
}

void solve() {
    int n;
    cin >> n;
    vi cnt1(n + 1), cnt2(n + 1);
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt1[a]++;
        cnt2[b]++;
        cnt[{a, b}]++;
    }

    get_factorial(n);

    int c1 = 1, c2 = 1;
    for (auto x: cnt1) {
        c1 = mul(c1, factorial[x]);
    }
    for (auto x: cnt2) {
        c2 = mul(c2, factorial[x]);
    }

    int c = 1, pre = 0;
    for (auto [k, v]: cnt) {
        if (k.second < pre) {
            c = 0;
            break;
        }
        c = mul(c, factorial[v]);
        pre = k.second;
    }

    int ans = factorial[n];
    ans = sub(ans, add(c1, c2));
    ans = add(ans, c);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}