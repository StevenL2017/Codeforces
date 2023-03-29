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
    ll l, r; cin >> l >> r;

    vi left, right;
    auto x = l, y = r;
    while (x) {
        left.push_back(x % 10);
        x /= 10;
    }
    while (y) {
        right.push_back(y % 10);
        y /= 10;
    }

    if (ssz(left) < ssz(right)) {
        ll ans = 9;
        rep(i, ssz(left) - 1) {
            ans *= 10;
            ans += 9;
        }
        cout << ans << endl;
        return;
    }

    if (left.back() + 1 < right.back()) {
        ll ans = left.back() + 1;
        rep(i, ssz(left) - 1) {
            ans *= 10;
            ans += left.back() + 1;
        }
        cout << ans << endl;
        return;
    }

    int n = ssz(left), d = 0;
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    while (d < n) {
        if (left[d] == right[d]) {
            d++;
        } else {
            break;
        }
    }

    if (d == n) {
        cout << l << endl;
        return;
    }

    ll ans = l;
    int mn = 10;

    int dmx = -1, dmn = 10;
    ll res = 0;
    rep(i, d + 1) {
        dmx = max(dmx, left[i]);
        dmn = min(dmn, left[i]);
        res *= 10;
        res += left[i];
    }
    repa(i, left[d + 1], 10) {
        int cur_dmx = max(dmx, i), cur_dmn = min(dmn, i);
        if (cur_dmx - cur_dmn < mn) {
            auto temp = res;
            rep(i, n - 1 - d) {
                temp *= 10;
                temp += i;
            }
            if (temp >= l && temp <= r) {
                mn = cur_dmx - cur_dmn;
                ans = temp;
            }
        }
    }

    dmx = -1, dmn = 10;
    res = 0;
    rep(i, d + 1) {
        dmx = max(dmx, right[i]);
        dmn = min(dmn, right[i]);
        res *= 10;
        res += right[i];
    }
    repd(i, right[d + 1], -1) {
        int cur_dmx = max(dmx, i), cur_dmn = min(dmn, i);
        if (cur_dmx - cur_dmn < mn) {
            auto temp = res;
            rep(i, n - 1 - d) {
                temp *= 10;
                temp += i;
            }
            if (temp >= l && temp <= r) {
                mn = cur_dmx - cur_dmn;
                ans = temp;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}