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
    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vi a(n); in(a);

    vector<vector<ll>> f(n, vector<ll>(2, LLONG_MAX));
    f[0][0] = a[0] * 1ll * r1 + r3;
    f[0][1] = min((a[0] + 1) * 1ll * r1, 1ll * r2);
    repa(i, 1, n) {
        f[i][0] = min(f[i][0], f[i - 1][0] + d + a[i] * 1ll * r1 + r3);
        f[i][0] = min(f[i][0], f[i - 1][1] + d + a[i] * 1ll * r1 + r3 + d + r1 + d);
        f[i][0] = min(f[i][0], f[i - 1][1] + d + min((a[i] + 1) * 1ll * r1, 1ll * r2) + d + r1 + d + r1);
        f[i][1] = min(f[i][1], f[i - 1][0] + d + min((a[i] + 1) * 1ll * r1, 1ll * r2));
        f[i][1] = min(f[i][1], f[i - 1][1] + d + min((a[i] + 1) * 1ll * r1, 1ll * r2) + d + r1 + d);
        if (i == n - 1) {
            f[i][0] = min(f[i][0], f[i - 1][1] + d + a[i] * 1ll * r1 + r3 + d + r1);
        }
    }

    cout << f[n - 1][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}