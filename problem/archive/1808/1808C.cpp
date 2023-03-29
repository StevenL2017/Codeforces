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

    int n = ssz(left), d = n;
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    rep(i, n) {
        if (left[i] != right[i]) {
            d = i;
            break;
        }
    }

    if (d == n) {
        cout << l << endl;
        return;
    }

    ll pre = 0;
    int dmx = -1, dmn = 10;
    rep(i, d) {
        pre *= 10;
        pre += left[i];
        dmx = max(dmx, left[i]);
        dmn = min(dmn, left[i]);
    }

    ll ans = l;
    int mn = 10;
    repa(i, left[d], right[d] + 1) {
        rep(j, 10) {
            auto cur = pre;
            cur *= 10;
            cur += i;
            rep(k, n - 1 - d) {
                cur *= 10;
                cur += j;
            }
            if (cur >= l && cur <= r) {
                auto cur_dmx = max({dmx, i, j});
                auto cur_dmn = min({dmn, i, j});
                if (mn > cur_dmx - cur_dmn) {
                    mn = cur_dmx - cur_dmn;
                    ans = cur;
                }
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