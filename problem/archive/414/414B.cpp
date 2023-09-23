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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vi> f(k, vi(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        f[0][i] = 1;
    }
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = j; x <= n; x += j) {
                f[i][x] += f[i - 1][j];
                f[i][x] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[k - 1][i];
        ans %= MOD;
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