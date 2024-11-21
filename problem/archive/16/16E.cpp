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

void solve() {
    int n;
    cin >> n;
    vector<vector<long double>> a(n, vector<long double>(n));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    int m = 1 << n;
    vector<long double> f(m);
    f[m - 1] = 1.0;
    for (int mask = m - 1; mask > 0; mask--) {
        int c = __builtin_popcount(mask);
        if (c == 1) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (j == i || !(mask >> j & 1)) {
                    continue;
                }
                f[mask ^ (1 << j)] += (long double)f[mask] * a[i][j] / (long double)(c * (c - 1));
                f[mask ^ (1 << i)] += (long double)f[mask] * a[j][i] / (long double)(c * (c - 1));
            }
        }
    }

    cout.precision(10);
    for (int i = 0; i < n; i++) {
        cout << f[1 << i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}