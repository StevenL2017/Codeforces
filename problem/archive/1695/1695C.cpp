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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    rep(i, n) in(a[i]);

    if ((n + m - 1) & 1) {
        cout << "NO\n";
        return;
    }

    vector<vi> mn(n, vi(m, INT_MAX)), mx(n, vi(m, INT_MIN));
    rep(i, n) {
        rep(j, m) {
            if (i == 0 && j == 0) {
                mn[i][j] = a[i][j];
                mx[i][j] = a[i][j];
            }
            else if (i == 0) {
                mn[i][j] = mn[i][j - 1] + a[i][j];
                mx[i][j] = mx[i][j - 1] + a[i][j];
            }
            else if (j == 0) {
                mn[i][j] = mn[i - 1][j] + a[i][j];
                mx[i][j] = mx[i - 1][j] + a[i][j];
            }
            else {
                mn[i][j] = min(mn[i][j - 1], mn[i - 1][j]) + a[i][j];
                mx[i][j] = max(mx[i][j - 1], mx[i - 1][j]) + a[i][j];
            }
        }
    }

    if (mn[n - 1][m - 1] > 0 || mx[n - 1][m - 1] < 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}