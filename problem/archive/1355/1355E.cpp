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

    m = min(m, a + r);
    sorta(h);
    vector<ll> pre(n + 1, 0);
    rep(i, n) pre[i + 1] = pre[i] + h[i];

    auto calc = [&] (ll target) -> ll {
        ll ans = INF_LL;
        auto idx = upper_bound(h.begin(), h.end(), target) - h.begin();
        auto s1 = target * idx - pre[idx], s2 = tot - pre[idx] - target * (n - idx);
        if (s1 >= s2) ans = min(ans, s2 * m + (s1 - s2) * a);
        else ans = min(ans, s1 * m + (s2 - s1) * r);
        return ans;
    };
    
    ll ans = INF_LL;
    rep(i, n) {
        ans = min(ans, calc(h[i]));
    }
    ans = min(ans, calc(tot / n));
    ans = min(ans, calc((tot + n - 1) / n));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}