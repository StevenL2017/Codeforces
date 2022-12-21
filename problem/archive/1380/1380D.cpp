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
    ll x, k, y; cin >> x >> k >> y;
    vi a(n), b(m); in(a), in(b);

    ll ans = 0;
    int i = 0, j = 0;
    int left = 0, right = 0, c = 0, mx = 0;
    while (i < n && j < m) {
        while (i < n && a[i] != b[j]) {
            c++;
            mx = max(mx, a[i]);
            i++;
        }

        if (i == n) {
            cout << -1 << endl;
            return;
        }

        right = a[i];
        if (c) {
            int start = (mx > left && mx > right ? 1 : 0);
            ll cur = LLONG_MAX;
            repa(z, start, c / k + 1) {
                cur = min(cur, z * x + (c - z * k) * y);
            }
            if (cur == LLONG_MAX) {
                cout << -1 << endl;
                return;
            }
            ans += cur;
        }

        left = right;
        right = 0;
        c = 0;
        mx = 0;
        j++;
        i++;
    }

    if (i == n && j < m) {
        cout << -1 << endl;
        return;
    }

    if (i < n && j == m) {
        while (i < n) {
            c++;
            mx = max(mx, a[i]);
            i++;
        }

        if (c) {
            int start = (mx > left && mx > right ? 1 : 0);
            ll cur = LLONG_MAX;
            repa(z, start, c / k + 1) {
                cur = min(cur, z * x + (c - z * k) * y);
            }
            if (cur == LLONG_MAX) {
                cout << -1 << endl;
                return;
            }
            ans += cur;
        }
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