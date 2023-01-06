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

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    ll s = 0, mx = LLONG_MIN;
    bool neg = false;
    rep(i, n) {
        s += abs(a[i]);
        mx = max(mx, a[i]);
        if (a[i] < 0) neg = true;
    }

    if (neg) {
        if (mx >= 0) cout << s << endl;
        else cout << s + 2 * mx << endl;
    } else {
        ll ans = LLONG_MIN;
        rep(i, n - 1) {
            ans = max(ans, s - a[i] - a[i + 1] + abs(a[i] - a[i + 1]));
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}