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
    vi u(n), s(n); in(u); in(s);

    ll tot = 0;
    vector<vi> a(n);
    rep(i, n) {
        tot += s[i];
        a[u[i] - 1].push_back(s[i]);
    }

    vector<ll> d(n + 1, 0);
    rep(i, n) {
        if (a[i].empty()) continue;
        sorta(a[i]);
        int m = ssz(a[i]);
        for (int k = 1, j = 0; k <= m; k++) {
            while (j < m && j < (m % k)) {
                d[k] += a[i][j];
                j++;
            }
            while (j >= 0 && j > (m % k)) {
                j--;
                d[k] -= a[i][j];
            }
        }
        if (m < n) {
            d[m + 1] += accumulate(a[i].begin(), a[i].end(), 0ll);
        }
    }
    repa(i, 1, n + 1) {
        d[i] += d[i - 1];
    }

    vector<ll> ans(n);
    rep(i, n) {
        ans[i] = tot - d[i + 1];
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}