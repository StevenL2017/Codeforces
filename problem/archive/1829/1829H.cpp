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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    int m = 1 << 7;
    vector<vi> f(n + 1, vi(m));
    f[0][m - 1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j] = add(f[i + 1][j], f[i][j]);
            f[i + 1][j & a[i]] = add(f[i + 1][j & a[i]], f[i][j]);
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        if (__builtin_popcount(j) == k) {
            ans = add(ans, f[n][j]);
        }
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