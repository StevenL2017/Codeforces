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
    int n; cin >> n;
    vector<ll> k(n), h(n);
    in(k); in(h);

    ll t = k.back(), x = h.back();
    repd(i, n - 2, -1) {
        h[i] = max(h[i], ap_an(x - 1, -1, t - k[i]));
        t = k[i];
        x = h[i];
    }

    ll ans = 0;
    t = 0, x = 0;
    rep(i, n) {
        if (h[i] <= k[i] - t) {
            ans += ap_sum(h[i], -1, h[i]);
            x = h[i];
        } else {
            auto an = ap_an(x + 1, 1, k[i] - t);
            ans += ap_an_sum(x + 1, an, k[i] - t);
            x = an;
        }
        t = k[i];
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