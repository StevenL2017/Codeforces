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
const int Z = 1e5 + 3;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<vi> f(2, vi(Z * 2));
    f[0][Z] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < Z * 2; j++) {
            f[1][j] = 0;
        }
        for (int j = 0; j < Z * 2; j++) {
            if (f[0][j] == 0) continue;
            int nj = j + a[i];
            if (nj < Z * 2) {
                f[1][nj] = add(f[1][nj], f[0][j]);
            }
            if (nj != Z && Z * 2 - nj >= 0 && Z * 2 - nj < Z * 2) {
                f[1][Z * 2 - nj] = add(f[1][Z * 2 - nj], f[0][j]);
            }
        }
        f[0] = f[1];
    }

    int ans = 0;
    for (int i = 0; i < Z * 2; i++) {
        ans = add(ans, f[0][i]);
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