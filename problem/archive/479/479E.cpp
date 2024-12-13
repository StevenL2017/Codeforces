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

void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    a--; b--;

    vi f(n + 1);
    f[a] = 1;
    while (k--) {
        vi g(n + 1);
        for (int i = 0; i < n; i++) {
            int d = abs(i - b);
            int l = max(0, i - d + 1);
            int r = min(n - 1, i + d - 1);
            g[l] = add(g[l], f[i]);
            g[r + 1] = add(g[r + 1], -f[i]);
        }
        for (int i = 0; i < n; i++) {
            g[i + 1] = add(g[i + 1], g[i]);
        }
        for (int i = 0; i < n; i++) {
            g[i] = add(g[i], -f[i]);
        }
        f = g;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, f[i]);
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