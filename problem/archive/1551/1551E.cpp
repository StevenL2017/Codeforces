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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    vector<vi> f(n + 1, vi(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j + 1 == a[i]) {
                f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
            } else {
                f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]);
            }
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        }
    }

    for (int j = n; j >= 0; j--) {
        if (f[n][j] >= k) {
            cout << n - j << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}