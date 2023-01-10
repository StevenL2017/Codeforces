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
    ll n, C; cin >> n >> C;
    vector<ll> a(C + 1, 0);
    rep(i, n) {
        ll c, d, h;
        cin >> c >> d >> h;
        a[c] = max(a[c], d * h);
    }
    for (int c = 1; c <= C; c++) {
        for (int cc = c; cc <= C; cc += c) {
            a[cc] = max(a[cc], a[c] * (cc / c));
        }
    }
    for (int c = 1; c <= C; c++) {
        a[c] = max(a[c], a[c - 1]);
    }

    ll m; cin >> m;
    vi ans(m, -1);
    rep(i, m) {
        ll d, h;
        cin >> d >> h;
        auto idx = upper_bound(a.begin(), a.end(), d * h) - a.begin();
        if (idx > C) continue;
        ans[i] = idx;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}