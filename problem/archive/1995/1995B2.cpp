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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), c(n);
    in(a);
    in(c);

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(c[idx[i]], m / a[idx[i]]) * a[idx[i]]);
        if (i > 0 && a[idx[i - 1]] + 1 == a[idx[i]]) {
            ll ax = a[idx[i - 1]], ay = a[idx[i]];
            ll cx = c[idx[i - 1]], cy = c[idx[i]];
            ll kx = min(cx, m / ax);
            ll rem = m - kx * ax;
            ll ky = min(cy ,rem / ay);
            rem -= ky * ay;
            ll r = min({kx, cy - ky, rem});
            ans = max(ans, (kx - r) * ax + (ky + r) * ay);
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