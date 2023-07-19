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
const int MAXN = 1e5 + 3;

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

int perm(int n, int k) {
    if (k > n) return 0;
    return divide(factorial[n], factorial[n - k]);
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vi idx(n, -1);
    for (int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }

    int ans = 1;
    int left = idx[0], right = idx[0], mex = 1;
    vi vis(n, 0);
    vis[0] = 1;
    while (mex < n) {
        int pre_mex = mex;
        if (idx[pre_mex] < left) {
            for (int i = left - 1; i >= idx[pre_mex]; i--) {
                vis[a[i]] = 1;
            }
            left = idx[pre_mex];
        } else {
            for (int i = right + 1; i <= idx[pre_mex]; i++) {
                vis[a[i]] = 1;
            }
            right = idx[pre_mex];
        }
        while (mex < n && vis[mex]) mex++;
        ans = mul(ans, perm(right - left + 1 - pre_mex - 1, mex - pre_mex - 1));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_factorial();
    int t = 1;
    cin >> t;
    while (t--) solve();
}