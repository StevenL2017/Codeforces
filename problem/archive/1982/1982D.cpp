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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> h(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(h[i]);
    }
    vector<string> a(n);
    in(a);

    ll d = 0;
    vector<vi> pre(n + 1, vi(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d += a[i][j] == '1' ? h[i][j] : -h[i][j];
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + (a[i][j] == '1' ? 1 : -1);
        }
    }

    if (d == 0) {
        cout << "YES" << endl;
        return;
    }

    int g = 0;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < m - k + 1; j++) {
            int cur = pre[i + k][j + k] - pre[i][j + k] - pre[i + k][j] + pre[i][j];
            g = gcd(g, abs(cur));
        }
    }
    if (g == 0 || d % g) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}