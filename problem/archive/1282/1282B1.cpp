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
    int n, p, k;
    cin >> n >> p >> k;
    vi a(n); in(a);

    sorta(a);
    vector<ll> pre(n + 1, 0);
    vector<vi> f(k, vi(1, 0));
    rep(i, n) {
        pre[i + 1] = pre[i] + a[i];
        if (i >= k - 1) {
            f[(i + 1) % k].push_back(f[(i + 1) % k].back() + a[i]);
        }
    }

    int ans = 0;
    rep(i, k) {
        int c1 = upper_bound(f[i].begin(), f[i].end(), p) - f[i].begin();
        int res = p - f[i][c1 - 1];
        int c2 = upper_bound(pre.begin(), pre.end(), res) - pre.begin() - 1;
        c2 = min(c2, (c1 > 1 ? i : n));
        ans = max(ans, (c1 - 1) * k + c2);
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