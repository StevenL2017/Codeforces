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
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n); in(a);

    sorta(a);
    vector<ll> pre(n + 1, 0);
    rep(i, n) pre[i + 1] = pre[i] + a[i];

    auto check = [&] (int x) -> bool {
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1]) continue;
            auto l = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
            auto r = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin() - 1;
            auto tot = l * 1ll * a[i] - pre[l] + pre[n] - pre[r + 1] - (n - 1 - r) * 1ll * (a[i] + x);
            if (tot <= k) return true;
            l = lower_bound(a.begin(), a.end(), a[i] - x) - a.begin();
            r = upper_bound(a.begin(), a.end(), a[i]) - a.begin() - 1;
            tot = l * 1ll * (a[i] - x) - pre[l] + pre[n] - pre[r + 1] - (n - 1 - r) * 1ll * a[i];
            if (tot <= k) return true;
        }
        return false;
    };

    int left = 0, right = a.back() - a.front(), ans = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
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