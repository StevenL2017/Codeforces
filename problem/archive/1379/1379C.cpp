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
    int n, m; cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];

    vi c = a;
    sorta(c);
    vector<ll> suf(m + 1, 0);
    repd(i, m - 1, -1) {
        suf[i] = suf[i + 1] + c[i];
    }

    ll ans = 0;
    rep(i, m) {
        int idx = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
        idx = max(idx, m - n);
        int cnt = n - (m - idx);
        ll h = suf[idx];
        if (cnt > 0 && a[i] < b[i]) h += 1ll * a[i] + 1ll * b[i] * (cnt - 1);
        else h += 1ll * b[i] * cnt;
        ans = max(ans, h);
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