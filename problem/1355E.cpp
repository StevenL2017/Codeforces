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
    ll n, a, r, m;
    cin >> n >> a >> r >> m;
    vector<ll> h(n); ll tot = 0;
    rep(i, n) {
        cin >> h[i];
        tot += h[i];
    }

    sorta(h);
    ll ans = min((h[n - 1] * n - tot) * a, (tot - h[0] * n) * r);
    ll pre = 0, suf = tot;
    rep(i, n) {
        auto k = m - a - r;
        auto b = (h[i] * i - pre) * a + (suf - h[i] * (n - i)) * r;
        ll x = 0;
        if (k < 0) {
            x = min(h[i] * i - pre, suf - h[i] * (n - i));
        }
        ans = min(ans, k * x + b);
        pre += h[i];
        suf -= h[i];
    }

    auto target = tot / n;
    auto mod = tot % n;
    ll d = 0;
    rep(i, n - mod) {
        d += abs(target - h[i]);
    }
    repa(i, n - mod, n) {
        d += abs(target + 1 - h[i]);
    }
    if (!mod) {
        ans = min(ans, d / 2 * m);
    } else {
        ans = min(ans, d / 2 * m + min((n - mod) * a, mod * r));
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