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

    vector<vector<ll>> f(n, vector<ll>(2, LLONG_MAX));
    f[0][0] = f[0][1] = 0;
    int mn = a[0], mx = a[0];
    repa(i, 1, n) {
        int cur_mn = a[i], cur_mx = a[i];
        if (i < n - 1) {
            if (a[i] <= s) {
                cur_mn = 0;
                cur_mx = a[i];
            } else {
                cur_mn = min(s, a[i] - s);
                cur_mx = max(s, a[i] - s);
            }
        }
        f[i][0] = min(f[i - 1][0] + mx * 1ll * cur_mn, f[i - 1][1] + mn * 1ll * cur_mn);
        f[i][1] = min(f[i - 1][0] + mx * 1ll * cur_mx, f[i - 1][1] + mn * 1ll * cur_mx);
        mn = cur_mn;
        mx = cur_mx;
    }

    cout << min(f[n - 1][0], f[n - 1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}