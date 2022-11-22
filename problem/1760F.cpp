#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    ll mx = 0;
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (mx * d < c) {
        cout << "Impossible" << endl;
        return;
    }

    sortd(a);
    ll tot = 0;
    rep(i, min(d, n)) {
        tot += a[i];
    }
    if (tot >= c) {
        cout << "Infinity" << endl;
        return;
    }

    auto check = [&] (ll k) -> bool {
        k++;
        ll cnt = 0;
        rep(i, min(k, n)) {
            cnt += a[i];
        }
        cnt *= d / k;
        auto mod = d % k;
        rep(i, min(mod, n)) {
            cnt += a[i];
        }
        return cnt >= c;
    };

    ll left = 0, right = d, ans = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
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