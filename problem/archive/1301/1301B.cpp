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
    int n; cin >> n;
    vi a(n); in(a);

    int m = 0, mn = INT_MAX, mx = INT_MIN;
    rep(i, n - 1) {
        if (a[i] > -1 && a[i + 1] > -1)
            m = max(m, abs(a[i] - a[i + 1]));
        if (a[i] > -1 && (i - 1 >= 0 && a[i - 1] == -1)) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        if (a[i] > -1 && (i + 1 < n && a[i + 1] == -1)) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }
    if (a[n - 1] > -1 && (n - 2 >= 0 && a[n - 2] == -1)) {
        mn = min(mn, a[n - 1]);
        mx = max(mx, a[n - 1]);
    }

    int k = (mn + mx) / 2;
    m = max({m, mx - k, k - mn});
    cout << m << " " << k << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}