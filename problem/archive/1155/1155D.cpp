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
    int n, x; cin >> n >> x;
    vector<ll> a(n); in(a);

    ll ans = 0;
    vector<ll> f(3, 0);
    rep(i, n) {
        auto pre = f[0], cur = f[1], suf = f[2];
        auto np = max(pre + a[i], a[i]);
        auto nc = max(pre + a[i] * x, a[i] * x);
        nc = max(nc, cur + a[i] * x);
        auto ns = max(cur + a[i], a[i]);
        ns = max(ns, suf + a[i]);
        ans = max(ans, np);
        ans = max(ans, nc);
        ans = max(ans, ns);
        f[0] = np, f[1] = nc, f[2] = ns;
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