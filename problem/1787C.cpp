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
    int n, s; cin >> n >> s;
    vi a(n); in(a);

    vi x, y(1, a[0]);
    repa(i, 1, n - 1) {
        if (a[i] <= s) {
            if (a[i - 1] <= s || a[i - 1] <= a[i + 1]) {
                x.push_back(a[i]);
                y.push_back(0);
            } else {
                x.push_back(0);
                y.push_back(a[i]);
            }
        } else {
            if (a[i - 1] <= s || a[i - 1] <= a[i + 1]) {
                x.push_back(max(s, a[i] - s));
                y.push_back(min(s, a[i] - s));
            } else {
                x.push_back(min(s, a[i] - s));
                y.push_back(max(s, a[i] - s));
            }
        }
    }
    x.push_back(a[n - 1]);

    ll ans = 0;
    rep(i, n - 1) {
        ans += x[i] * 1ll * y[i];
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