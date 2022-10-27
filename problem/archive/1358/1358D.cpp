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
const ll  INF_LL = 9e18 + 7;

long long ap_an(int a1, int d, int n) {
    return (long long)(1ll * a1 + 1ll * (n - 1) * d);
}

long long ap_sum(int a1, int d, int n) {
    return (long long)(1ll * n * a1 + 1ll * n * (n - 1) * d / 2);
}

long long ap_an_sum(int a1, int an, int n) {
    return (long long)(1ll * n * (a1 + an) / 2);
}

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> d(n); in(d);

    reverse(d.begin(), d.end());
    vector<ll> pre, tot;
    pre.push_back(0);
    tot.push_back(0);
    rep(i, n) {
        pre.push_back(pre.back() + d[i]);
        tot.push_back(tot.back() + ap_an_sum(d[i], 1, d[i]));
    }

    ll ans = 0;
    repa(i, 1, n + 1){
        int idx = upper_bound(pre.begin(), pre.end(), x + pre[i - 1]) - pre.begin();
        ll hug = tot[idx - 1] - tot[i - 1] + ap_sum(d[(idx - 1) % n], -1, x + pre[i - 1] - pre[idx - 1]);
        ans = max(ans, hug);
        pre.push_back(pre.back() + d[i - 1]);
        tot.push_back(tot.back() + ap_an_sum(d[i - 1], 1, d[i - 1]));
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