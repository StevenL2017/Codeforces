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

int calc(ll x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;

    ll ans = LLONG_MAX;
    int mx = n / 9;
    rep(i, 10) {
        rep(j, mx + 1) {
            ll x = i, c1 = 10;
            rep(_, j) {
                x += c1 * 9;
                c1 *= 10;
            }
            int s = calc(x);
            rep(c, k) {
                s += calc(x + c + 1);
            }
            if (n >= s && (n - s) % (k + 1) == 0) {
                auto d = (n - s) / (k + 1);
                ll y = min(d, 8), c2 = 10;
                d -= min(d, 8);
                while (d > 0) {
                    y += c2 * min(d, 9);
                    c2 *= 10;
                    d -= min(d, 9);
                }
                ans = min(ans, y * c1 + x);
            }
        }
    }

    cout << (ans < LLONG_MAX ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}