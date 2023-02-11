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
    vector<pair<long double, long double>> pts(n);
    bool pos = false, neg = false;
    rep(i, n) {
        cin >> pts[i].first >> pts[i].second;
        if (pts[i].second > 0) pos = true;
        else neg = true, pts[i].second = -pts[i].second;
    }

    if (pos && neg) {
        cout << -1 << endl;
        return;
    }

    long double eps = 1e-9;
    auto check = [&] (long double R) -> bool {
        long double l = -1e16 - 1, r = 1e16 + 1;
        rep(i, n) {
            auto x = pts[i].first, y = pts[i].second;
            auto b = -2 * x, c = x * x + y * y - 2 * y * R;
            auto d = b * b - 4 * c;
            if (d < -eps) return false;
            d = sqrt(d);
            auto x1 = x - d / 2, x2 = x + d / 2;
            l = max(l, x1);
            r = min(r, x2);
        }
        return l <= r + eps;
    };

    long double left = 0, right = 1e16;
    long double err = 1e16, ans = -1e16;
    while (err > eps) {
        auto mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
        err = abs(mid - ans);
        ans = mid;
    }

    cout.precision(16);
    cout << fixed << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}