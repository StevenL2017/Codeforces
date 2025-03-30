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
const int N = 2e5 + 3;

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
    int n;
    cin >> n;
    vi a(N), l(N, 1), r(N, 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = 1; i < N; i++) {
        l[i] = 1ll * l[i - 1] * (a[i] + 1) % (MOD - 1);
    }
    for (int i = N - 2; i >= 0; i--) {
        r[i] = 1ll * r[i + 1] * (a[i] + 1) % (MOD - 1);
    }

    int ans = 1;
    for (int i = 1; i < N - 1; i++) {
        if (a[i] == 0) continue;
        int cur = 1ll * a[i] * (a[i] + 1) / 2 % (MOD - 1) * (1ll * l[i - 1] * r[i + 1] % (MOD - 1)) % (MOD - 1);
        ans = mul(ans, binpow(i, cur));
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