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
    int n; cin >> n;
    vector<ll> a(n); in(a);

    ll k = 0; vector<ll> d(n, a[0]);
    rep(i, n - 1) {
        d[i + 1] = a[i + 1] - a[i];
        k += max(0ll, d[i + 1]);
    }

    cout << (ll)ceil((double)(d[0] + k) / 2.0) << endl;

    int q; cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        
        if (l == 0) d[0] += x;
        if (l > 0) {
            if (d[l] > 0) k -= d[l];
            d[l] += x;
            if (d[l] > 0) k += d[l];
        }
        if (r + 1 < n) {
            if (d[r + 1] > 0) k -= d[r + 1];
            d[r + 1] -= x;
            if (d[r + 1] > 0) k += d[r + 1];
        }

        cout << (ll)ceil((double)(d[0] + k) / 2.0) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}