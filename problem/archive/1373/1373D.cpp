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

    ll ans = 0;
    vector<ll> x, y;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
        if (i + 1 < n) x.push_back(a[i + 1] - a[i]);
        if (i - 1 >= 0) y.push_back(a[i - 1] - a[i]);
    }

    auto calc = [&] (vector<ll>& b) -> ll {
        if (b.empty()) return 0;
        ll mx = b[0], f = b[0];
        repa(i, 1, ssz(b)) {
            f = max(f + b[i], b[i]);
            mx = max(mx, f);
        }
        return mx;
    };

    cout << max({ans, ans + calc(x), ans + calc(y)}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}