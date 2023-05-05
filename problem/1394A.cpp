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
    int n, d, m;
    cin >> n >> d >> m;
    vi a(n); in(a);

    vector<ll> b, c;
    rep(i, n) {
        if (a[i] > m) {
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }

    int k = ssz(b);
    if (k == 0) {
        ll tot = 0;
        rep(i, n) {
            tot += a[i];
        }
        cout << tot << endl;
        return;
    }

    sortd(b);
    sortd(c);
    repa(i, 1, k) {
        b[i] += b[i - 1];
    }
    repa(i, 1, n - k) {
        c[i] += c[i - 1];
    }
    rep(i, k) {
        c.push_back(c.back());
    }

    ll ans = 0;
    repa(i, (k + d) / (1 + d), k + 1) {
        if ((i - 1) * 1ll * (d + 1) < n) {
            ans = max(ans, b[i] + c[n - (i - 1) * (d + 1)]);
        }
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