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
    ll a, b, q;
    cin >> a >> b >> q;

    ll n = a * b;
    vi pre(n + 1, 0);
    repa(i, 1, n + 1) {
        pre[i] = pre[i - 1];
        if ((i % a) % b != (i % b) % a) pre[i]++;
    }

    auto calc = [&] (ll x) -> ll {
        auto cnt = x / n, rem = x % n;
        return cnt * 1ll * pre[n] + 1ll * pre[rem];
    };

    vector<ll> ans(q, 0);
    rep(i, q) {
        ll l, r; cin >> l >> r;
        ans[i] = calc(r) - calc(l - 1);
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}